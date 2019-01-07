#include "load.h"

void load::set_attributes(){
 out.set_timestep(SIM_STEP, sc_core::SC_SEC);
}

void load::initialize(){
	int j =0;
	
	ifstream in("bighouse.txt");
	if(!in){
		cout<<"Cannot open file.!!!\n"<<endl;
		exit(-1);
	}
	for(j=0;j<SIZE;j++){
		in>>wave[j];
	}
	in.close();
}

void load::processing(){
	
	out.write(((wave[i]*1000)/0.95)/0.8);// Effciency, Power factor
	//out.write(wave[i]);// Effciency, Power factor
	//cout<<wave[i]<<endl;	
	i++;
}
