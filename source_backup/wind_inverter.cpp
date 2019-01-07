#include "wind_inverter.h"

void inverter_wt::set_attributes()
{
  I.set_timestep(SIM_STEP, sc_core::SC_SEC);
  //Pwind.set_timestep(0.001, sc_core::SC_SEC);
  Pwind.set_timestep(SIM_STEP, sc_core::SC_SEC);
  //Pwind.set_rate(1000);
}

void inverter_wt::initialize()
{
  eta = 0.98; 
}

void inverter_wt::processing()
{
   I.write((Pwind.read()*eta)/V.read());
   //I.write(20*eta/V.read());
}
