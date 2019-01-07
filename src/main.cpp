#include "systemc.h"
#include "systemc-ams.h"
#include "battery.h"
#include "cti_bus.h"
#include "pv_panel.h"
#include "wind_turbine.h"
#include "battery_converter.h"
#include "pv_converter.h"
#include "wind_inverter.h"
#include "house1.h"
#include "house2.h"
#include "house5.h"


int sc_main(int argc, char* argv[]){
	//Signals for battery parts
	sca_tdf::sca_signal<double> Ibatt, Vbatt, SOC, Ibatt_cnv, Vbatt_cnv;

	//Signals for PV parts
	sca_tdf::sca_signal<double> Power_pv, Ipv_cnv, Vpv_cnv;  

	//Signals for wind turbine
	sca_tdf::sca_signal<double> Power_wind, Vwind_inv, Iwind_inv, wind_speed;

	sca_tdf::sca_signal<double> Phouse1, Phouse2, Phouse5;	

	//Singals for management
	//
	
	battery batt("batt");
	pv_panel pv("pv");
	windturbine wt("wt");

	converter_b batt_con("batt_con");
	converter_pv pv_con("pv_con");
	inverter_wt wt_inv("wt_inv");
	
	house1 house1("house1");	
	house2 house2("house2");	
	house5 house5("house5");	

	cti_bus cti_bus("cti_bus");

	
	//----------------------Binding-------------------------------------------------
	//Battery
	batt.I(Ibatt);
	batt.V(Vbatt);
	batt.SOC(SOC);

	//Battery converter
	batt_con.in(Vbatt);
	batt_con.in2(Ibatt_cnv);
	batt_con.in3(Vbatt_cnv);
	batt_con.out(Ibatt);	

	//PV panel
	pv.P(Power_pv);
	
	//PV converter
	pv_con.in(Power_pv);
	pv_con.in2(Vpv_cnv);
	pv_con.out(Ipv_cnv);

	//Wind turbine
	wt.power(Power_wind);
	wt.windspeed(wind_speed);

	//Wind inverter
	wt_inv.Pwind(Power_wind);
	wt_inv.V(Vwind_inv);
	wt_inv.I(Iwind_inv);

	//Load side -> A village is filled with 1 2 5 houses' combination.
	house1.out(Phouse1);
	house2.out(Phouse2);
	house5.out(Phouse5);

	//BUS
	cti_bus.SOC(SOC);
	cti_bus.Ibatt_cnv(Ibatt_cnv);
	cti_bus.Vbatt_cnv(Vbatt_cnv);

	cti_bus.Ipv_cnv(Ipv_cnv);
	cti_bus.Vpv_cnv(Vpv_cnv);

	cti_bus.Iwind_inv(Iwind_inv);
	cti_bus.Vwind_inv(Vwind_inv);

	cti_bus.Phouse1(Phouse1);		
	cti_bus.Phouse2(Phouse2);		
	cti_bus.Phouse5(Phouse5);		
	

	//sca_util::sca_decimation(1000);
	// To store the values during simualtion
	sca_util::sca_trace_file* atf = sca_util::sca_create_tabular_trace_file( "trace.txt" );
//	atf->set_mode(sca_decimation(1000));
//	sca_util::sca_trace(atf,SOC,"SOC");

	sca_util::sca_trace(atf,Phouse1,"Phouse1");
	sca_util::sca_trace(atf,wind_speed,"Wind");

	sca_util::sca_trace(atf,Power_wind,"Power_wind");
	sca_util::sca_trace(atf,Power_pv,"Power_pv");

//	sc_start();
	sc_start(2, sc_core::SC_SEC);
	cout<<"YUKAI:The WHOLE  SIMULATION STOP AT "<<" @"<<sc_time_stamp()<<endl;
	
	//sca_util::sca_close_tabular_trace_file( atf );	
	
	return 0;
}
