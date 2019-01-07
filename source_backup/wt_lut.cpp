#include "wt_lut.h"

void windturbine::set_attributes()
{
	power.set_timestep(SIM_STEP, sc_core::SC_SEC);
	//P.set_delay(1);
}

void windturbine::initialize()
{
  unsigned int i;
  ifstream inwind; 
  
  inwind.open("wind_one_week_1s.txt");
  if (!inwind) {
    cout << "Cannot open file.\n"<< endl;
    exit(-1);
  }
  for (i=0;  i<SAMPLES; i++) {
    inwind >> wind[i];
  }
  inwind.close();

 
}


void windturbine::processing()
{  
  
  double wtp; 
  
  wtp = 11200*sin(0.1562*wind[t]-0.623) + 2015*sin(0.6514*wind[t]+0.2421); 
  //wtp = wind[t]*0.5;

  
  power.write(wtp); 
  windspeed.write(wind[t]);
  
  t++; 
  if (t == SAMPLES) {
    cout<<"YUKAI: STOP BY SAMPLES"<<endl;
    cout<<"Simulation ended: "<<" @"<<sc_time_stamp()<<endl;
    sc_stop();
  }
}

