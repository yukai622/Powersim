#include "imperial_defs.h"
#include "mechanical_tdf.h"

void mechanical_tdf::set_attributes()
{
  ddtWm.set_timestep(TIMESTEP);
  ddtWg.set_timestep(TIMESTEP);
  ddtWm.set_delay(1);
  ddtWg.set_delay(1);
}

void mechanical_tdf::initialize()
{
  Tm = 0.0; 
  varWm = 2.10001; 
  first = true; 
  ddtWm.initialize(0.4949); 
  ddtWg.initialize(-338.4232); 
}

void mechanical_tdf::processing()
{
  // derive variation of angular speeds given mechanical torque, 
  // generator torque and wind torque
  
  if(first){
     first = !first; 
  }
  else{
   varWm = Wm.read();  
  }
  
  Tm = (stiffness/gear_ratio) * theta.read() + (damping/gear_ratio) * (Wg.read() - varWm);
  Tms.write(Tm); 
  ddtWm.write((-Tw.read()+Tm)/Hm); 


  ddtWg.write((-Te.read()-(Tm/gear_ratio))/Hg);
}
