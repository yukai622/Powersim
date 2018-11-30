#include "systemc-ams.h"

SCA_TDF_MODULE (mechanical_tdf)
{
  sca_tdf::sc_in<double> Wm; // mechanical angular speed, generator angular speed 
  sca_tdf::sca_in<double> Tw, Wg; // wind torque 
  sca_tdf::sca_in<double> Te; // generator torque 
  sca_tdf::sc_in<double> theta; // angle between rotors

  sca_tdf::sc_out<double> ddtWm, ddtWg; // first derivatives of Wm, Wg
  
  sc_signal<double> Tms;
  
  SC_CTOR(mechanical_tdf): Wm("Wm"), Wg("Wg"), Tw("Tw"), Te("Te"), 
			    theta("theta"), ddtWm("ddtWm"), ddtWg("ddtWg") {}

  void set_attributes(); 
  void initialize(); 
  void processing(); 
  
private: 
  
  double Tm; // mechanical torque
  double varWm; 
  bool first;
};
