#include "systemc-ams.h"

SCA_TDF_MODULE (generator_eq)
{
  sca_tdf::sca_in<double> Wg; // generator angular speed 
  sca_tdf::sca_out<double> ddtFdr, ddtFqr; // magnetic flux derivatives 
  sca_tdf::sca_out<double> Idr, Iqr; // stator direct and quadrature axis currents
  sca_tdf::sca_in<double> idtFdr, idtFqr; // magnetic flux linkage for stator direct and quadrature axis 
  sca_tdf::sca_out<double> P, I; // generated power and current
  
  SC_CTOR(generator_eq): Wg("Wg"), ddtFdr("ddtFdr"), ddtFqr("ddtFqr"), Idr("Idr"), Iqr("Iqr"), idtFdr("idtFdr"), idtFqr("idtFqr"), P("P"), I("I"){}

  void set_attributes(); 
  void initialize(); 
  void processing(); 

  sc_signal<double> sIds, sS, sIqs, sIdr_i, sIqr_i, sFiqs, sFids, sddtFdr_i, sddtFqr_i;  
  
private: 
  
  double Ids, S, Iqs, Idr_i, Iqr_i, Fiqs, Fids, ddtFdr_i, ddtFqr_i, power;  
  double Ids_new, Iqs_new, Idr_i_new, Iqr_i_new, Fiqs_new, Fids_new, ddtFdr_i_new, ddtFqr_i_new;  
  bool first;
};
