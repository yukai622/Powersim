#include "battery_fre.h"

void battery_fre::set_attributes(){
	out.set_timestep(SIM_STEP,sc_core::SC_SEC);
	out2.set_timestep(SIM_STEP,sc_core::SC_SEC);
	out.set_delay(1);
	out2.set_delay(1);
}

void battery_fre::initialize(){

}


void battery_fre::processing(){

	double tmpcurrent = in.read();
	double tempsoc = in2.read();
	double tmpfrequency;
	double cap_act_current;
	double delta_crate;
	

        //Rated Cpacity Effect
	 cap_act_current = -44870*pow(tmpcurrent,0.132)+438000; // Modify the correct capacity
	 delta_crate=(((tmpcurrent*SIM_STEP)/(cap_act_current*1.0))-((tmpcurrent*SIM_STEP)/(3600*150)));

	


	//out.write(delta_crate);
	out.write(0.0);
	out2.write(0.0);
	//out2.write(delta_freq);
	

}
