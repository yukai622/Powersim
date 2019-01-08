#include "wind_inverter.h"

void inverter_wt::set_attributes()
{
  I.set_timestep(SIM_STEP, sc_core::SC_SEC);
  Pwind.set_timestep(SIM_STEP, sc_core::SC_SEC);

}

void inverter_wt::initialize()
{

}

void inverter_wt::processing()
{

   I.write((Pwind.read()*0.95)/VBUS);

}
