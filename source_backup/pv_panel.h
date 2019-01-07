#include "systemc-ams.h"
#include "tstep.h"

//#define SAMPLES 

SCA_TDF_MODULE (pv_panel)
{  
//   sca_tdf::sca_out<double> I, V, P; 
  sca_tdf::sca_out<double> P; 
  double Gtop[SAMPLES], Gwest[SAMPLES];// Define in tstep.h 
  unsigned int t;

  SCA_CTOR(pv_panel): P("P"), t(0) {}

  void set_attributes();

  void initialize();

  void processing();
};
