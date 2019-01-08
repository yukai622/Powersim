#include "systemc-ams.h"
#include "tstep.h"

SCA_TDF_MODULE(battery_voc){
	sca_tdf::sca_in<double> in, in2, in3; //SOC, V_lost_C, V_lost_F
	sca_tdf::sca_out<double> out, out2, out3, out4; //Voc, Resistor, SOC, SOC
	

	SCA_CTOR(battery_voc):out("out"),out2("out2"),out3("out3"),out4("out4"),tmpsoc(1.0){}

	void set_attributes();

	void initialize();

	void processing();

	private:
	double tmpsoc;

};
