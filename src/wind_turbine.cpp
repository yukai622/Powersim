#include "wind_turbine.h"

void windturbine::set_attributes()
{
	power.set_timestep(SIM_STEP, sc_core::SC_SEC);
	//P.set_delay(1);
}

void windturbine::initialize()
{
	//unsigned int i;
	//ifstream in_wind_speed; 
//tb1 old
//tb2 tb3 tb4 new tb5 new tb6 old tb7 old tb8 new
	in_wind_speed.open("../one_year_inputs/one_year_wind.txt");

	if (!in_wind_speed) {
		cout << "Cannot open file.\n"<< endl;
		exit(-1);
	}

	/*
	   for (i=0;  i<LENGTH; i++) {
	   in_wind_speed >> wind[i];
	   }
	   in_wind_speed.close();
	   */

}


void windturbine::processing()
{  

	double wind_high;

	if(counter%600 == 0){ // Determined by the time step of trace	
		in_wind_speed >> wind;
		//wind_high = wind*(log(50/0.3)/log(3/0.3)); // Notice the height of wind spedd
	}

	double wtp; 

	//cout<<wind<<"@"<<sc_time_stamp()<<endl; 

	//wtp =(11200*sin(0.15628*wind-0.623) + 2015*sin(0.6514*wind+0.2421))*0.788; 
	wtp =WT_NUM *((12570*exp(-pow((wind-17.1)/7.068,2))+5762*exp(-pow((wind-10.88)/3.319,2)))*0.72+200); // for increase wind speed for 50m height


	power.write(wtp); 

	windspeed.write(wind);



	if (t == LENGTH - 1) {
		cout<<"YUKAI Report: Wind Turbine works very well until to the end!"<<endl;
		//    cout<<"Simulation ended: "<<" @"<<sc_time_stamp()<<endl;
		in_wind_speed.close();
	}

	t++;
	counter++;

}

