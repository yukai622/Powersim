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

//tb1 6
//tb2 6 tb6
//tb3 7
//tb4 6
//tb5 6
//tb7 10
//tb8 2

void house1::processing(){

	if(counter%10 == 0 || counter == 0){
		house1powerfile >> rp;
		out.write(6*rp/0.95);// Effciency
		counter++;
	}else{
		out.write(6*rp/0.95);// Effciency
		counter++;
	}


}






