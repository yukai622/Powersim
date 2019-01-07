#include "battery_converter.h"

void converter_b::set_attributes()
{
  out.set_timestep(SIM_STEP, sc_core::SC_SEC);
  out.set_delay(1);
}

void converter_b::initialize(){

}

void converter_b::processing()
{
	double tmp_vin = in.read();
	double tmp_iout = in2.read();
	double tmp_vout = in3.read();

	//double efficiency = (0.24 * pow(tmp_vin, 2) - 0.0000663 * pow(tmp_vout, 2) - 0.00545 * pow(tmp_iout, 2) + 0.000713 * tmp_vin + 0.0116 * tmp_vout + 0.00689 * tmp_iout - 0.036967) / 4.5;
        double efficiency = 0.99;
//	eta.write(efficiency);
        out.write(tmp_iout * tmp_vout / (efficiency * tmp_vin));
}
