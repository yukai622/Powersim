#include "imperial_defs.h"
#include "aerodynamic.h"

void aerodynamic::set_attributes()
{
  Tw.set_timestep(TIMESTEP);
}

void aerodynamic::initialize()
{
  ro = ro0;
  first = true; 
  varWm = 2.10001;
}

void aerodynamic::processing()
{
  
  if(first){
     first = !first; 
  }
  else{
   varWm = Wm.read();  
  }
  
  lambda = varWm * radius / wind.read(); 
  gamma = lambda/(1-0.035*lambda); 
  Cp = 0.5*(116/gamma-5)*exp(-21/gamma); 

  // wind torque
  torque = PI/2 * Cp * ro * pow(radius,2) * pow(wind.read(),3)/varWm;
  Tw.write(torque); 
}
