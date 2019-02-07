#include "house2.h"

void house2::set_attributes(){
 out.set_timestep(SIM_STEP, sc_core::SC_SEC);

}

void house2::initialize(){
	int j =0;
	
	house2powerfile.open("../loads/UKLOAD/one_week_h2.txt");
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

	house2powerfile >> rp;

//	cout<< rp<<"\t" << ap<<"\t" << pf<<endl;
//	cout<<rp<<"The real power value"<<endl;
//	cout<<"The apparent power is"<<ap<<endl;
//	cout<<"The power factor is"<<pf<<endl;


	out.write(5*rp/0.95);// Effciency


}






