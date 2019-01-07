#include "turbine.h"

void turbine::set_attributes()
{
  I.set_timestep(pow(10,-3), sc_core::SC_SEC);
  I.set_delay(1); 
  V.set_delay(1); 
  Pm.set_delay(1); 
  Pe.set_delay(1); 
  T.set_delay(1); 
}

void turbine::initialize()
{
  ro = 1.25; // air density = 1.25 Kg/m^3
  beta = 0.0; // fixed pitch angle
  lambda = 7; // tip speed ratio - TBD
  radius = 2.5; // blade radius - TBD
  c1 = 0.5176;
  c2 = 116;
  c3 = 0.4;
  c4 = 5;
  c5 = 21;
  c6 = 0.0068;
  PI = 3.141592653589793; 
  lambda_i = 1/(1/(lambda + 0.08*beta) - 0.035/(pow(beta,3)+1)); 
  Cp = c1 * (c2/lambda_i - c3*beta -c4) * exp(-c5/lambda_i) + c6 * lambda; // Betz factor 
  Ct = Cp/lambda; 
  
}

void turbine::processing()
{
  // torque
  torque = Ct * ro * (PI/2) * pow(radius,3)*pow(wind.read(),2);
  
  // angular speed
  w = lambda * wind.read()/radius;
  
  // rotational speed r/min
  n = (w * 60)/(2 * PI); 
  
  // output ports
  T.write(torque); 
  I.write(0.0); 
  V.write(0.0); 
  Pm.write(0.0); 
  Pe.write(0.0); 
}
