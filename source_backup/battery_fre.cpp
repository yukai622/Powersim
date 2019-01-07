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
//	double cap_act_frequency;
	double delta_crate;
//	double delta_freq;
	

        //Rated Cpacity Effect
	 cap_act_current = -44870*pow(tmpcurrent,0.132)+438000; // Modify the correct capacity
	//cap_act_frequency = (7920*1.23)*(-294.0*pow(tmpfrequency,0.9085)+1.0);
	/*
         if(tempsoc >0.5){
	 	delta_crate=(((tmpcurrent*SIM_STEP)/(cap_act_current*0.895))-((tmpcurrent*SIM_STEP)/(3600*4)));
	 }else{
	 	delta_crate=(((tmpcurrent*SIM_STEP)/(cap_act_current*0.795))-((tmpcurrent*SIM_STEP)/(3600*4)));
	 }
	*/
	 delta_crate=(((tmpcurrent*SIM_STEP)/(cap_act_current*1.0))-((tmpcurrent*SIM_STEP)/(3600*150)));
//	 delta_freq = 0.0; //To simplify

	



	
	//cout <<"Lost"<<tmpcount<<endl;
	//if(delta_freq>0)
	//cout<<"delta_freq "<<delta_freq<<" @ "<<sc_time_stamp()<<endl;
 	//cout<<"delta_crate "<<delta_freq<<" @ "<<sc_time_stamp()<<endl;

	out.write(delta_crate);
	//out.write(0.0);
	out2.write(0.0);
	//out2.write(delta_freq);
	//
	

}
