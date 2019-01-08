#include "systemc-ams.h"
#include "tstep.h"

SCA_TDF_MODULE(converter_b){
	//sca_tdf::sca_in<double> in, in2, in3; // Vbatt, Iload, Vbus
	sca_tdf::sca_in<double> in, in2; // Vbatt, Iload
	sca_tdf::sca_out<double> out;//Iin;

	//sca_tdf::sca_out<double> eta;//efficiency

	SCA_CTOR(converter_b){}

	void set_attributes();

	void initialize();

	// processes to calculate efficiency and battery current load
	void processing();
};
