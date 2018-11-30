#include "systemc-ams.h"
#include "generator_Te.h"
#include "generator_lsf.h"
#include "generator_eq.h"

SC_MODULE (generator)
{
  sca_tdf::sca_out<double> Te; // generator torque
  sca_tdf::sca_out<double> P, I; // output power and current
  sca_tdf::sca_in<double> Wg; // generator angular speed

  generator_Te * teModule; 
  generator_lsf * lsfModule; 
  generator_eq * eqModule; 
  
  sca_tdf::sca_signal<double> Idr, idtFdr, idtFqr, Iqr, ddtFdr, ddtFqr;
  
  SCA_CTOR(generator): Te("Te"), P("P"), I("I"), Wg("Wg") {
    
    teModule = new generator_Te("teModule"); 
    lsfModule = new generator_lsf("lsfModule"); 
    eqModule = new generator_eq("eqModule");
    
    teModule->Idr(Idr); 
    teModule->idtFdr(idtFdr); 
    teModule->idtFqr(idtFqr); 
    teModule->Iqr(Iqr); 
    teModule->Te(Te); 
    
    lsfModule->ddtFdr(ddtFdr); 
    lsfModule->ddtFqr(ddtFqr); 
    lsfModule->idtFdr(idtFdr); 
    lsfModule->idtFqr(idtFqr); 

    eqModule->ddtFdr(ddtFdr);
    eqModule->ddtFqr(ddtFqr);
    eqModule->idtFdr(idtFdr);
    eqModule->idtFqr(idtFqr);
    eqModule->Idr(Idr); 
    eqModule->Iqr(Iqr); 
    eqModule->Wg(Wg);
    eqModule->P(P); 
    eqModule->I(I); 
  }
};
