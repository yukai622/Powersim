#include "systemc-ams.h"
#include "tstep.h"

#define Voltage_reference 430

SCA_TDF_MODULE(cti_bus){
	// Ports connect to battery
	sca_tdf::sca_in<double> SOC;
	sca_tdf::sca_out<double> Ibatt_cnv, Vbatt_cnv;
	//sca_tdf::sca_out<int> Enable_charge; //Control signals for charge or discharge

	// Ports connect to PV panel
	sca_tdf::sca_in<double> Ipv_cnv;
//	sca_tdf::sca_out<double> Vpv_cnv;

	//Ports connect to wind turbine	
	sca_tdf::sca_in<double> Iwind_inv;
	sca_tdf::sca_out<double> Vwind_inv;

	//Ports connect to Grid load
	sca_tdf::sca_in<double> Phouse1;
	sca_tdf::sca_in<double> Phouse2;
	sca_tdf::sca_in<double> Phouse5;

	// All signals
	//SCA_CTOR(cti_bus): vref_cti(430.0),Ibatt_tmp(0.0),total_power(0.0), SOC("SOC"), Ibatt_cnv("Ibatt_cnv"),Vbatt_cnv("Vbatt_cnv"), Ipv_cnv("Ipv_cnv"), Vpv_cnv("Vpv_cnv"), Iwind_inv("Iwind_inv"), Vwind_inv("Vwind_inv"), Phouse1("Phouse1"), Phouse2("Phouse2"), Phouse5("Phouse5") {}
	
	// Omit bus votage, define it as VBUS
	SCA_CTOR(cti_bus): vref_cti(430.0),Ibatt_tmp(0.0),total_power(0.0), SOC("SOC"), Ibatt_cnv("Ibatt_cnv"),Vbatt_cnv("Vbatt_cnv"), Ipv_cnv("Ipv_cnv"), Iwind_inv("Iwind_inv"), Vwind_inv("Vwind_inv"), Phouse1("Phouse1"), Phouse2("Phouse2"), Phouse5("Phouse5") {}

	void set_attributes();

	void initialize();

	void processing();

	private:
	 double vref_cti, Ibatt_tmp, total_power;

};

