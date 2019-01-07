#include "systemc-ams.h"

SC_MODULE (generator_lsf)
{
  sca_tdf::sca_in<double> ddtFdr, ddtFqr; // magnetic flux derivatives 
  sca_tdf::sca_out<double> idtFdr, idtFqr; // magnetic flux values 

  sca_lsf::sca_signal lsfFdr, lsfFqr, intFdr, intFqr; 

  sca_lsf::sca_tdf::sca_source * inFdr, * inFqr; // convert to LSF domain
  sca_lsf::sca_integ * fdrInteg, * fqrInteg; 
  sca_lsf::sca_tdf::sca_sink * outFdr, * outFqr; 
  
  SC_CTOR(generator_lsf): ddtFdr("ddtFdr"), ddtFqr("ddtFqr"), idtFdr("idtFdr"), idtFqr("idtFqr"){
    
    inFdr = new sca_lsf::sca_tdf::sca_source("inFdr", 1.0); 
    inFdr->inp(ddtFdr); 
    inFdr->y(lsfFdr); 
     
    fdrInteg = new sca_lsf::sca_integ("fdrInteg", 1.0, 2.799606);  
    fdrInteg->x(lsfFdr); 
    fdrInteg->y(intFdr); 
     
    outFdr = new sca_lsf::sca_tdf::sca_sink("outFdr"); 
    outFdr->x(intFdr);
    outFdr->outp(idtFdr); 

    inFqr = new sca_lsf::sca_tdf::sca_source("inFqr", 1.0); 
    inFqr->inp(ddtFqr); 
    inFqr->y(lsfFqr); 
     
    fqrInteg = new sca_lsf::sca_integ("fqrInteg", 1.0, 2.8004);  
    fqrInteg->x(lsfFqr); 
    fqrInteg->y(intFqr); 
     
    outFqr = new sca_lsf::sca_tdf::sca_sink("outFqr"); 
    outFqr->x(intFqr);
    outFqr->outp(idtFqr); 
  }
};
