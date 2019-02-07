#include "house5.h"

void house5::set_attributes(){
 out.set_timestep(SIM_STEP, sc_core::SC_SEC);

}

void house5::initialize(){
	int j =0;
	
	house5powerfile.open("../loads/UKLOAD/one_week_h5.txt");
	if(!house5powerfile){
		cout<<"Cannot open loads file.!!!\n"<<endl;
		
		exit(-1);
	}
//	for(j=0;j<3;j++){
//		in>>rp[j]>>ap[j]>>pf[j];
//	}
//	in.close();
	
}

void house5::processing(){

	house5powerfile >> rp;

//	cout<< rp<<"\t" << ap<<"\t" << pf<<endl;
//	cout<<rp<<"The real power value"<<endl;
//	cout<<"The apparent power is"<<ap<<endl;
//	cout<<"The power factor is"<<pf<<endl;


	out.write((rp*5)/0.95);// Effciency

}




