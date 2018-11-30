#include "imperial_defs.h"
#include "mechanical_delay.h"

void mechanical_delay::set_attributes()
{
  Wg_delayed.set_timestep(TIMESTEP);
}

void mechanical_delay::initialize()
{
}

void mechanical_delay::processing()
{
  Wg_delayed.write(Wg.read()); 
}
