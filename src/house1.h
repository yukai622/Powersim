#include "systemc-ams.h"
#include "tstep.h"

SCA_TDF_MODULE(house1){

	sca_tdf::sca_out<double>out; // Real Power = Apparent power * power factor
	
	ifstream house1powerfile;


	double rp; // real power
//	double ap; // apparent power
//	double pf; // power factor
	
	//SCA_CTOR(house1):out("out"), rp(0), ap(0), pf(0) {}
	SCA_CTOR(house1):out("out"), rp(0) {}

	void set_attributes();
	
	void initialize();

	void processing();


};
