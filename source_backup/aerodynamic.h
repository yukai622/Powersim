#include "systemc-ams.h"

SCA_TDF_MODULE (aerodynamic)
{
  sca_tdf::sca_out<double> Tw; // torque 
  sca_tdf::sca_in<double> wind; // wind speed 
  sca_tdf::sc_in<double> Wm; // mechanical angular speed 

  SCA_CTOR(aerodynamic): Tw("Tw"), wind("wind"), Wm("Wm") {}

  void set_attributes();
  void initialize();
  void processing();
  
private: 
  
  double ro; // air density
  double gamma, lambda; // speed ratio
  double Cp; // power coefficient
  double torque; // wind torque - internal variable
  bool first; 
  double varWm;
};
