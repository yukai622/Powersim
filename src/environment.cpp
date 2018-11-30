#include "environment.h"
#include "imperial_defs.h"

void environment::set_attributes(){
  wind.set_timestep(TIMESTEP);
  set_timestep(TIMESTEP);
}

void environment::initialize(){
  ifs.open("./wind_one_day_1ms.txt", std::ifstream::in); 
}

void environment::processing(){
  double temp, temp2; 

  if(ifs.eof()){
    wind.write(0.0);
    cout<<"YUKAI:STOP BY WIND SPEED in environment file!"<<endl;
    sc_stop(); 
  }
  else{
    ifs >> temp;  
    wind.write(temp); 
  }
}

environment::~environment(){
  ifs.close(); 
}
