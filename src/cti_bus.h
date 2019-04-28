#include "systemc-ams.h"
#include "tstep.h"

#define Voltage_reference 430

SCA_TDF_MODULE(cti_bus){
	// Ports connect to battery
	sca_tdf::sca_in<double> SOC;
	//sca_tdf::sca_out<double> Ibatt_cnv, Vbatt_cnv;
	sca_tdf::sca_out<double> Ibatt_cnv;
	//sca_tdf::sca_out<int> Enable_charge; //Control signals for charge or discharge

	// Ports connect to PV panel
	sca_tdf::sca_in<double> Ipv_cnv;
//	sca_tdf::sca_out<double> Vpv_cnv;

	//Ports connect to wind turbine	
	sca_tdf::sca_in<double> Iwind_inv;
//	sca_tdf::sca_out<double> Vwind_inv;

	//Ports connect to Grid load
	sca_tdf::sca_in<double> Phouse1;
	sca_tdf::sca_in<double> Phouse2;
	sca_tdf::sca_in<double> Phouse5;

	// Buy or Sell from/to utility grid
	sca_tdf::sca_out<double> Buy_from_grid;
	sca_tdf::sca_out<double> Sell_to_grid;

	// All signals
	//SCA_CTOR(cti_bus): vref_cti(430.0),Ibatt_tmp(0.0),total_power(0.0), SOC("SOC"), Ibatt_cnv("Ibatt_cnv"),Vbatt_cnv("Vbatt_cnv"), Ipv_cnv("Ipv_cnv"), Vpv_cnv("Vpv_cnv"), Iwind_inv("Iwind_inv"), Vwind_inv("Vwind_inv"), Phouse1("Phouse1"), Phouse2("Phouse2"), Phouse5("Phouse5") {}
	
	// Omit bus votage, define it as VBUS
	SCA_CTOR(cti_bus): Ibatt_tmp(0.0),total_load(0.0),total_generation(0.0), SOC("SOC"), Ibatt_cnv("Ibatt_cnv"), Ipv_cnv("Ipv_cnv"), Iwind_inv("Iwind_inv"), Buy_from_grid("Buy_from_grid"), Sell_to_grid("Sell_to_grid"), Phouse1("Phouse1"), Phouse2("Phouse2"), Phouse5("Phouse5"), total_buy_f1(0.0), total_buy_f2(0.0),total_buy_f3(0.0), total_sell_f1(0.0),total_sell_f2(0.0), total_sell_f3(0.0), total_buy(0.0),total_sell(0.0), counter(0) {}

	void set_attributes();

	void initialize();

	void processing();

	private:
//	 double vref_cti, Ibatt_tmp, total_power;
	 double counter;
	 double Ibatt_tmp, total_load, total_generation;
	 double total_buy_f1, total_buy_f2, total_buy_f3, total_sell_f1, total_sell_f2, total_sell_f3, total_sell, total_buy;
};

