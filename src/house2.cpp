#include "house2.h"

void house2::set_attributes(){
 out.set_timestep(SIM_STEP, sc_core::SC_SEC);

}

void house2::initialize(){
	int j =0;
	
	house2powerfile.open("../one_year_inputs/one_year_h2.txt");
	if(!house2powerfile){
		cout<<"Cannot open loads file.!!!\n"<<endl;
		
		exit(-1);
	}
//	for(j=0;j<3;j++){
//		in>>rp[j]>>ap[j]>>pf[j];
//	}
//	in.close();
	
}

void house2::processing(){

	if(counter%10 == 0 || counter == 0){
	house2powerfile >> rp;
	out.write(6*rp/0.95);// Effciency
	counter++;
	}else{
	out.write(6*rp/0.95);// Effciency
	counter++;
	}

}






