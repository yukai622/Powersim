#include "house1.h"

void house1::set_attributes(){
 out.set_timestep(SIM_STEP, sc_core::SC_SEC);
}

void house1::initialize(){
	int j =0;
	
	house1powerfile.open("../loads/UKLOAD/one_week_h1.txt");
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

	house1powerfile >> rp >> ap >> pf;

//	cout<< rp<<"\t" << ap<<"\t" << pf<<endl;
//	cout<<rp<<"The real power value"<<endl;
//	cout<<"The apparent power is"<<ap<<endl;
//	cout<<"The power factor is"<<pf<<endl;


	out.write(rp/0.95);// Effciency

}






