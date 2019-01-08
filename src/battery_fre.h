#include "systemc-ams.h"
#include "tstep.h"


SCA_TDF_MODULE(battery_fre){
	sca_tdf::sca_in<double> in,in2; //I load current. SOC
	sca_tdf::sca_out<double> out,out2;//V_lost_C, V_lost_F



	SCA_CTOR(battery_fre):out("out"),out2("out2"){}

	void set_attributes();

	void initialize();

	void processing();



};
