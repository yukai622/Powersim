#include "pv_panel.h"

void pv_panel::set_attributes()
{
	P.set_timestep(SIM_STEP, sc_core::SC_SEC);
	//P.set_delay(1);
}

void pv_panel::initialize()
{
  unsigned int i;
  ifstream ing; 
  
  ing.open("sun_one_week.txt");
  if (!ing) {
    cout << "Cannot open file.\n"<< endl;
    exit(-1);
  }
  for (i=0;  i<SAMPLES; i++) {
    ing >> Gtop[i];
  }
  ing.close();

  ing.open("sun_one_week.txt");
  if (!ing) {
    cout << "Cannot open file.\n"<< endl;
    exit(-1);
  }
  for (i=0;  i<SAMPLES; i++) {
    ing >> Gwest[i];
  }
  ing.close();
  
}


void pv_panel::processing()
{  
  
  double Ptop, Pback; 
  
  Ptop = 4.752e-09*pow(Gtop[t],3) - 7.352e-06*pow(Gtop[t],2) + 0.02238*Gtop[t] - 0.6954; 
  Pback = 4.752e-09*pow(Gwest[t],3) - 7.352e-06*pow(Gwest[t],2) + 0.02238*Gwest[t] - 0.6954;

 // cout<<Gtop[t]<<endl;

  if (Ptop < 0){
  P.write(0);
  }else{  
  P.write((Ptop * 6 + Pback * 4)*20); 
  }
  
  t++; 
  if (t == SAMPLES) {
    cout<<"YUKAI: STOP BY PV PV"<<endl;
    cout<<"Simulation ended: "<<" @"<<sc_time_stamp()<<endl;
    sc_stop();
  }
}

