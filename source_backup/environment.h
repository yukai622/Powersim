#include "systemc-ams.h"


SCA_TDF_MODULE (environment)
{
  sca_tdf::sca_out<double> wind; // wind speed 

  SCA_CTOR(environment): wind("wind"){}

  void set_attributes();
  void initialize();
  void processing();
  ~environment(); 
  
private: 
  std::ifstream ifs, ifs2;
};
