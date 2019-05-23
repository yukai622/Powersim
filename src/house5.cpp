#include "house5.h"

void house5::set_attributes(){
 out.set_timestep(SIM_STEP, sc_core::SC_SEC);

}

void house5::initialize(){
	int j =0;
	
	house5powerfile.open("../one_year_inputs/one_year_h5.txt");
	if(!house5powerfile){
		cout<<"Cannot open loads file.!!!\n"<<endl;
		
		exit(-1);
	}
	
}
// tb1 = 5
// tb2 = 5 tb6
// tb3 = 5
// tb4 = 4
// tb5 = 4
// tb7 = 3
// tb8 = 7

void house5::processing(){

	if(counter%10 == 0 || counter == 0){
	house5powerfile >> rp;
	out.write((rp*5)/0.95);// Effciency
	counter++;
	}else{
	out.write((rp*5)/0.95);// Effciency
	counter++;
	}

}




