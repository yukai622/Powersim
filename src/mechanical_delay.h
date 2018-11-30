#include "systemc-ams.h"

SCA_TDF_MODULE (mechanical_delay)
{
  sca_tdf::sca_in<double> Wg; 
  sca_tdf::sca_out<double> Wg_delayed; 
  
  SC_CTOR(mechanical_delay): Wg("Wm"), Wg_delayed("Wm_delayed"){}

  void set_attributes(); 
  void initialize(); 
  void processing(); 
  
private: 
};
