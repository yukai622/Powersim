#include "systemc-ams.h"
#include "tstep.h"

SCA_TDF_MODULE(inverter_wt)
{
  sca_tdf::sca_out<double> I; // current connect to bus
 //sca_tdf::sca_in<double> Pwind, V; //power generated from wind, Bus voltage 
  sca_tdf::sca_in<double> Pwind; //Power generated from wind

  
  //SCA_CTOR(inverter_wt): I("I"), V("V"), Pwind("Pwind") {}
  SCA_CTOR(inverter_wt): I("I"), Pwind("Pwind") {}

  void set_attributes();

  void initialize();

  void processing();
};
