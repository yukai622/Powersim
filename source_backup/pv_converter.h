#include "systemc-ams.h"
#include "tstep.h"

SCA_TDF_MODULE(converter_pv){
	sca_tdf::sca_in<double> in, in2; // PowerPV, Vbus
	sca_tdf::sca_out<double> out;//I current out of converter
//	sca_tdf::sca_out<double> eta;//efficiency is constant

	SCA_CTOR(converter_pv){}

	void set_attributes();

	void initialize();

	// processes to calculate efficiency and battery current load
	void processing();
};
