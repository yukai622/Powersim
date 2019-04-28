#include "systemc-ams.h"
#include "tstep.h"


SCA_TDF_MODULE (pv_panel)
{ 

  sca_tdf::sca_out<double> P; 
 // sca_tdf::sca_in<int> pnum; 
  sca_tdf::sca_out<double> sun_irradiance; 

 // double Gtop[LENGTH], Gwest[LENGTH];// Define in tstep.h 
  double Gtop, Gwest;// Define in tstep.h 

  unsigned int t;

  ifstream top; // To store the irradiance profile

  SCA_CTOR(pv_panel): P("P"), sun_irradiance("sun_irradiance"), t(0), counter(0) {}


  int pv_number;
  void set_data(int &pv_num);
  void set_attributes();

  void initialize();

  void processing();


  private:
  int counter,pv_num;

};
