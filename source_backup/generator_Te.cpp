#include "imperial_defs.h"
#include "generator_Te.h"

void generator_Te::set_attributes()
{
  Te.set_timestep(TIMESTEP);
  Te.set_delay(1);
}

void generator_Te::initialize()
{
  Te.initialize(0.0);
}

void generator_Te::processing()
{
  
  Te.write(idtFqr.read() * Idr.read() - idtFdr.read() * Iqr.read()); 
}
