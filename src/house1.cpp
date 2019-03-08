#include "house1.h"

void house1::set_attributes(){
	out.set_timestep(SIM_STEP, sc_core::SC_SEC);
}

void house1::initialize(){
	int j =0;

	house1powerfile.open("../one_year_inputs/one_year_h1.txt");
	if(!house1powerfile){
		cout<<"Cannot open loads file.!!!\n"<<endl;

		exit(-1);
	}
	//	for(j=0;j<3;j++){
	//		in>>rp[j]>>ap[j]>>pf[j];
	//	}
	//	in.close();

}

void house1::processing(){

	if(counter%10 == 0 || counter == 0){
		house1powerfile >> rp;
		out.write(7*rp/0.95);// Effciency
		counter++;
	}else{
		out.write(7*rp/0.95);// Effciency
		counter++;
	}


}






