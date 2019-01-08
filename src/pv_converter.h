#include "systemc-ams.h"
#include "tstep.h"

SCA_TDF_MODULE(converter_pv){

	//sca_tdf::sca_in<double> in, in2; // PowerPV, Vbus
	sca_tdf::sca_in<double> in; // PowerPV, Omitting Vbus since it is a constant value, define it in tstep.h  
	sca_tdf::sca_out<double> out;//I current out of converter
//	sca_tdf::sca_out<double> eta;//efficiency is constant

	SCA_CTOR(converter_pv){}

	void set_attributes();

	void initialize();

	// Processes to calculate efficiency and current flow through PV panel
	void processing();
};
