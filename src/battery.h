#include "systemc-ams.h"
#include "battery_char.h"
#include "battery_voc.h"
#include "battery_fre.h"



SC_MODULE(battery){
	// interface and internal components declaration
	sca_tdf::sca_in<double> I; // Ib current
//	sca_tdf::sca_in<int> snum; // s number
//	sca_tdf::sca_in<int> pnum; // p number
	sca_tdf::sca_out<double> V; // Vb battery voltage
	sca_tdf::sca_out<double> SOC; //SOC


	//Connecting signals
	sca_tdf::sca_signal<double> Voc, Rs, deltaf, deltac, tmpsoc;

	//Instantiation of battery componenets
	battery_voc* voc;
	battery_char* batt;
	battery_fre* freq;

	SC_CTOR(battery): I("I"),V("V"),SOC("SOC")
	{

		voc = new battery_voc("voc");
		batt = new battery_char("batt");
   		freq = new battery_fre("freq");

		voc->in(I);
		voc->in2(deltac);
		voc->in3(deltaf);
//		voc->in4(snum);
//		voc->in5(pnum);
		voc->out(Voc);
		voc->out2(Rs);
		voc->out3(SOC);
		voc->out4(tmpsoc);
	
		batt->in(Rs);
		batt->in2(I);
		batt->in3(Voc);
		batt->out(V);

		freq->in(I);
		freq->in2(tmpsoc);
		freq->out(deltac);
		freq->out2(deltaf);
	}

};








