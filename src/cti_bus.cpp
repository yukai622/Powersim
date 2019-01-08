#include "cti_bus.h"

void cti_bus::set_attributes(){
	Ibatt_cnv.set_delay(1);
	Vbatt_cnv.set_delay(1);
//	Vpv_cnv.set_delay(1);
//	Vwind_inv.set_delay(1);
}

void cti_bus::initialize(){

}

void cti_bus::processing(){

	// The constant dc bus voltage connection 
	Vbatt_cnv.write(VBUS); //dcdc converter for battery
	//Vpv_cnv.write(vref_cti);   //dcdc converter for pv panel
	//Vwind_inv.write(vref_cti); //dcac converter for wind turbine

	// Compute the total power comsumption from load side
	total_power = (Phouse1.read() + Phouse2.read() + Phouse5.read());

	// Determine charge or discharge battery
	Ibatt_tmp = (total_power - (Ipv_cnv.read()*VBUS) - (Iwind_inv.read()*VBUS))/VBUS;
	
	
	if(Ibatt_tmp > 0){
		Ibatt_cnv.write(0.0001);
	}else{
		Ibatt_cnv.write(0.0001);
	}

}
