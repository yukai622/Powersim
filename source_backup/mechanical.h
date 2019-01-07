#include "systemc-ams.h"
#include "mechanical_tdf.h"
#include "mechanical_lsf.h"

SC_MODULE (mechanical)
{
  sc_out<double> Wm; // mechanical angular speed 
  sca_tdf::sca_out<double> Wg; // generator angular speed 
  sca_tdf::sca_in<double> Tw; // wind torque 
  sca_tdf::sca_in<double> Te; // generator torque 

  mechanical_tdf * tdf; 
  mechanical_lsf * lsf; 
  
  sc_signal<double> Wmi, Wei, theta2, Wm_delay, theta_delay, Wmi_delay; 
  sc_signal<double> ddtWm, ddtWg;
  sca_tdf::sca_signal<double> Wg_delay;
  
  SC_CTOR(mechanical): Wm("Wm"), Tw("Tw"), Te("Te") {
    
    tdf = new mechanical_tdf("mechanical_tdf"); 
    lsf = new mechanical_lsf("mechanical_lsf");
    
    tdf->Tw(Tw); 
    tdf->Te(Te); 
    tdf->Wm(Wm); 
    tdf->Wg(Wg);
    tdf->theta(theta2); 
    tdf->ddtWm(ddtWm);
    tdf->ddtWg(ddtWg); 

    lsf->Wmi(Wmi); 
    lsf->Wgi(Wei);
    lsf->Wm(Wm); 
    lsf->Wg(Wg);
    lsf->theta(theta2); 
    lsf->ddtWm(ddtWm);
    lsf->ddtWg(ddtWg); 
  }
};
