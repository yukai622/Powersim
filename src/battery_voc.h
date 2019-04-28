#include "systemc-ams.h"
#include "tstep.h"

SCA_TDF_MODULE(battery_voc){
	sca_tdf::sca_in<double> in, in2, in3; //SOC, V_lost_C, V_lost_F, batt_s, batt_p
	sca_tdf::sca_out<double> out, out2, out3, out4; //Voc, Resistor, SOC, SOC
//int batt_s,batt_p;
	
	SCA_CTOR(battery_voc):out("out"),out2("out2"),out3("out3"),out4("out4"),tmpsoc(0.9),t(0){}


	int batt_snum, batt_pnum;
	void set_data(int &batt_s, int &batt_p);

	void set_attributes();

	void initialize();

	void processing();

	private:
	double tmpsoc;
	int t;

};
