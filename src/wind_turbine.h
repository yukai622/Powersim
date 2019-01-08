#include "systemc-ams.h"
#include "tstep.h"
#include "math.h"


SCA_TDF_MODULE (windturbine)
{  
  
  sca_tdf::sca_out<double> power,windspeed; 

  double wind[LENGTH];// Define in tstep.h 

  unsigned int t;

  SCA_CTOR(windturbine): power("power"), windspeed("windspeed"),t(0) {}

  void set_attributes();

  void initialize();

  void processing();
};
