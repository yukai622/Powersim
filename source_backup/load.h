#include "systemc-ams.h"
#include "tstep.h"
#define SIZE 86400

SCA_TDF_MODULE(load){
	sca_tdf::sca_out<double>out; // Power
	unsigned int i;
	double wave[SIZE];
	double tmp;
	
	SCA_CTOR(load):out("out"),i(0) {}

	void set_attributes();
	
	void initialize();

	void processing();


};
