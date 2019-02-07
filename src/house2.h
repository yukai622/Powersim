#include "systemc-ams.h"
#include "tstep.h"

SCA_TDF_MODULE(house2){
	sca_tdf::sca_out<double>out; // Real Power = Apparent power * power factor
//	unsigned int i;
	
	ifstream house2powerfile;

	
//	SCA_CTOR(house2):out("out"), rp(0.0), ap(0.0), pf(0.0) {}
	SCA_CTOR(house2):out("out"), rp(0.0) {}

	void set_attributes();
	
	void initialize();

	void processing();


	private:
	double rp; // real power
//	double ap; // apparent power
//	double pf; // power factor
};
