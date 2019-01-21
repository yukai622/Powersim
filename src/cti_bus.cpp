#include "cti_bus.h"

void cti_bus::set_attributes(){
	Ibatt_cnv.set_delay(1);
//	Vbatt_cnv.set_delay(1);
//	Vpv_cnv.set_delay(1);
//	Vwind_inv.set_delay(1);
}

void cti_bus::initialize(){

}

void cti_bus::processing(){

	double batt_soc = SOC.read();

	// The constant dc bus voltage connection 
	//Vbatt_cnv.write(VBUS); //dcdc converter for battery
	//Vpv_cnv.write(vref_cti);   //dcdc converter for pv panel
	//Vwind_inv.write(vref_cti); //dcac converter for wind turbine

	// Compute the total power comsumption from load side
	total_load = (Phouse1.read() + Phouse2.read() + Phouse5.read());

//	cout << "Total load " << total_load << endl;
	// Compute the total generation from PV and Wind turbine
	total_generation = (Ipv_cnv.read() + Iwind_inv.read()) * VBUS;


//	cout << "Total generation " << total_generation << endl;

	// Determine charge or discharge battery, postive value means discharge
	Ibatt_tmp = (total_load - total_generation)/VBUS;
	
	
	if(Ibatt_tmp >= 0){ // Load is larger than generation

		Sell_to_grid.write(0.0); // Do not forget merge!

		if(batt_soc > 0.2 ){ // Battery has energy, can provilde power to load to compensate generation is not enough

			Ibatt_cnv.write(Ibatt_tmp); // Battery discharge current	
			Buy_from_grid.write(0.0); // Store the value of buy from grid
		
		}else { // Battery is dead, cannot provide any more; the power need buy from grid;

			Ibatt_cnv.write(0.0); // Battery no action;
			Buy_from_grid.write(Ibatt_tmp * VBUS); // Store the value of buy from grid

		}

	}else{ // Load is less than generation

		Buy_from_grid.write(0.0);

		if(batt_soc < 0.9){ // The extra power can be absorbed in battery
		
			Ibatt_cnv.write(Ibatt_tmp); // Battery charge current, it is an negative value
			Sell_to_grid.write(0.0); // Store the value for selling to grid
		
		}else { // Battery is fully charged, cannot charge anymore, the extra power can sell to grid

			Ibatt_cnv.write(0.0); // Battery no action
			Sell_to_grid.write(Ibatt_tmp * VBUS); // Store the value for selling to grid
		
		}
	}

}

















