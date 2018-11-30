#include "systemc-ams.h"

SCA_TDF_MODULE (generator_Te)
{
  sca_tdf::sca_in<double> Idr, Iqr; // stator direct and quadrature axis currents 
  sca_tdf::sca_in<double> idtFdr, idtFqr; // magnetic flux linkage for stator direct and quadrature axis 
  sca_tdf::sca_out<double> Te; // generator torque 

  SC_CTOR(generator_Te): Idr("Idr"), Iqr("Iqr"), idtFdr("idtFdr"), idtFqr("idtFqr"), Te("Te"){}

  void set_attributes(); 
  void initialize(); 
  void processing(); 

private: 
  
};
