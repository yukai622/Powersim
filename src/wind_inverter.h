#include "systemc-ams.h"
#include "tstep.h"

SCA_TDF_MODULE(inverter_wt)
{
  sca_tdf::sca_out<double> I; // current connect to bus
  sca_tdf::sca_in<double> Pwind, V; //power generated from wind, Bus voltage 
  //sca_tdf::sca_in<double> V; 
 // sca_tdf::sca_in<int> En; 

  double eta; 
  
  //inverter( sc_core::sc_module_name name_): I("I"), V("V"), En("En"),Ppv("Ppv") {}
  SCA_CTOR(inverter_wt): I("I"), V("V"), Pwind("Pwind") {}

  void set_attributes();

  void initialize();

  void processing();
};
