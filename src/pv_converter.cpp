#include "pv_converter.h"

void converter_pv::set_attributes()
{
  out.set_timestep(SIM_STEP, sc_core::SC_SEC);
  out.set_delay(1);
}

void converter_pv::initialize(){

}

void converter_pv::processing()
{
	double tmp_power = in.read();
	double tmp_vbus = in2.read();

        double efficiency = 0.95;
	
        out.write((efficiency * tmp_power)/tmp_vbus);
}
