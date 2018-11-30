#include "systemc-ams.h"

SC_MODULE(battery_char){

	// Interface and internal components declaration
	sca_tdf::sca_in<double>in,in2,in3; // Resistor, I load current, Voc affected by SOC
	sca_tdf::sca_out<double> out; //Vbatt
	
	sca_eln::sca_tdf::sca_isource* Ibatt;
	sca_eln::sca_tdf::sca_vsink* Vbatt;
	
	sca_eln::sca_tdf_vsource* Voc;
	sca_eln::sca_node n1,n2;
	sca_eln::sca_node_ref gnd;
	sca_eln::sca_tdf::sca_r* Rs;

	SC_CTOR(battery_char){
		// Voc voltage instantiation
		Voc = new sca_eln::sca_tdf_vsource("Voc");
		Voc->inp(in3);
		Voc->p(n1);
		Voc->n(gnd);
		// Internal resistance instantiation
		Rs = new sca_eln::sca_tdf::sca_r("Rs");
		Rs->p(n1);
		Rs->n(n2);
		Rs->scale=1.0;
		Rs->inp(in);
		//Load current instantiation
		Ibatt = new sca_eln::sca_tdf::sca_isource("Ibatt");
		Ibatt->inp(in2);
		Ibatt->p(n2);
		Ibatt->n(gnd);
		//Output voltage of the battery
		Vbatt = new sca_eln::sca_tdf::sca_vsink("Vbatt");
		Vbatt->p(n2);
		Vbatt->n(gnd);
		Vbatt->outp(out);
	
	}
	

};
