#include "imperial_defs.h"
#include "generator_eq.h"

#define THRESHOLD pow(10,-3)

void generator_eq::set_attributes()
{
  ddtFdr.set_timestep(TIMESTEP);
  ddtFqr.set_timestep(TIMESTEP);
  Idr.set_timestep(TIMESTEP);
  Iqr.set_timestep(TIMESTEP);
  idtFdr.set_timestep(TIMESTEP);
  idtFqr.set_timestep(TIMESTEP);
  P.set_timestep(TIMESTEP);
  I.set_timestep(TIMESTEP);
  P.set_delay(1);
  I.set_delay(1);
  ddtFdr.set_delay(1);
  ddtFqr.set_delay(1);
}

void generator_eq::initialize()
{
  Fiqs = 0.0; 
  Fids = 0.0; 
  first = true; 
}

void generator_eq::processing()
{
  bool stop; 
  
  if(first){
    first = !first; 
    S =  -1.05; 
    Ids =  25.7205177139132;   
    Iqs = -23.5701284511721; 
    Idr_i = -387.595129111054; 
    Iqr_i = 385.660629524179; 
    ddtFdr_i = 0.160761032888432; 
    ddtFqr_i = -0.145285036193433; 
    Fiqs = 1000.31121826429; 
    Fids = -999.714801445741; 
    power = Vds * (Ids - Iqs) + Vqs * (Ids - Iqs); 
  }
  else{
//     S =  1 - Wg.read(); 
//     Ids =  (Fiqs - 1000)/Rs;   
//     Iqs = -(Fids + 1000)/Rs; 
//     Idr_i = (idtFdr.read() - Xm*Ids)/Xr; 
//     Iqr_i = (idtFqr.read() - Xm*Iqs)/Xr; 
//     ddtFdr_i = -Rr*Idr_i + S*idtFqr.read(); 
//     ddtFqr_i = -Rr*Iqr_i - S*idtFdr.read(); 
//     Fiqs = Xs*Iqs + Xm*Iqr_i; 
//     Fids = Xs*Ids + Xm*Idr_i; 
//     power = Vds * (Ids - Iqs) + Vqs * (Ids - Iqs); 
    

    S =  1 - Wg.read();
    
    double idtFdr_read = idtFdr.read();
    double idtFqr_read = idtFqr.read();
  
//     stop = false; 
//     
//     while(!stop){

    Fids_new = -999.70170657088342026
	      + (1.3950413642039010548E-6) * idtFdr_read
	      - (0.00467813606185818792) * idtFqr_read;
    Ids_new = 24.637651012341070291
	      + (0.3866228150296023188) * idtFdr_read
	      + (1.1529267472760617151E-4) * idtFqr_read;
    Iqs_new = -24.652349513766923794
	      - (1.1529267472760617151E-4) * idtFdr_read
	      + (0.38662281502960231877) * idtFqr_read;
    Fiqs_new = 1000.2981155772493269
	      + (0.0046781360618581879204) * idtFdr_read
	      + (1.395041364204009475E-6) * idtFqr_read;
    Idr_i_new = -386.50752235487471264
		- (0.38662231005553289004) * idtFdr_read
		- (0.0018086742941651606543) * idtFqr_read;
    Iqr_i_new = 386.73810770432992495
		+ (0.0018086742941651606543) * idtFdr_read
		- (0.38662231005553288998) * idtFqr_read;

		  
    Idr_i = Idr_i_new; 
    Fids = Fids_new; 
    Iqr_i = Iqr_i_new; 
    Fiqs = Fiqs_new; 
    Iqs = Iqs_new; 
    Ids = Ids_new;
    
//       stop = (abs(Idr_i - Idr_i_new)<THRESHOLD) && (abs(Fids - Fids_new)<THRESHOLD) && (abs(Iqs - Iqs_new)<THRESHOLD) && (abs(Iqr_i - Iqr_i_new)<THRESHOLD) && (abs(Fiqs - Fiqs_new)<THRESHOLD) && (abs(Ids - Ids_new)<THRESHOLD); 
		  
//       Idr_i = Idr_i_new; 
//       Fids = Fids_new; 
//       Iqr_i = Iqr_i_new; 
//       Fiqs = Fiqs_new; 
//       Iqs = Iqs_new; 
//       Ids = Ids_new;
//     }
    
 /*   
    
    
    
    stop = false; 
    
    Idr_i_new = Idr_i; 
    Fids_new = Fids; 
    Iqr_i_new = Iqr_i; 
    Fiqs_new = Fiqs; 
    Iqs_new = Iqs; 
    Ids_new = Ids;
    
    int counter = 0; 
    
    while(!stop){
    
      Idr_i_new = (idtFdr.read() - Xm*Ids)/Xr; 
      Fids_new = Xs*Ids_new + Xm*Idr_i_new; 
      Iqs_new = -(Fids_new + 1000)/0.012100000000000; 
      Iqr_i_new = (idtFqr.read() - Xm*Iqs_new)/Xr; 
      Fiqs_new = Xs*Iqs_new + Xm*Iqr_i_new; 
      Ids_new =  (Fiqs_new - 1000)/0.012100000000000;   
      
      stop = (abs(Idr_i - Idr_i_new)<1) && (abs(Fids - Fids_new)<1) && (abs(Iqs - Iqs_new)<1) && (abs(Iqr_i - Iqr_i_new)<1) && (abs(Fiqs - Fiqs_new)<1) && (abs(Ids - Ids_new)<1); 
      cout<<"Stop: "<<stop<<endl;
      cout<<"Idr: "<<abs(Idr_i - Idr_i_new)<<", old: "<<Idr_i<<", new: "<<Idr_i_new<<endl; 
      cout<<"Fids: "<<abs(Fids - Fids_new)<<", old: "<<Fids<<", new: "<<Fids_new<<endl; 
      cout<<"Iqs: "<<abs(Iqs - Iqs_new)<<", old: "<<Iqs<<", new: "<<Iqs_new<<endl; 
      cout<<"Iqr_i: "<<abs(Iqr_i - Iqr_i_new)<<", old: "<<Iqr_i<<", new: "<<Iqr_i_new<<endl; 
      cout<<"Fiqs: "<<abs(Fiqs - Fiqs_new)<<", old: "<<Fiqs<<", new: "<<Fiqs_new<<endl; 
      cout<<"Ids: "<<abs(Ids - Ids_new)<<", old: "<<Ids<<", new: "<<Ids_new<<endl; 
      cout<<endl;
      
      //stop = true;
      counter++; 
      
      if(counter == 5){
	stop = true;
	sc_stop();
      }
      
      Idr_i = Idr_i_new; 
      Fids = Fids_new; 
      Iqr_i = Iqr_i_new; 
      Fiqs = Fiqs_new; 
      Iqs = Iqs_new; 
      Ids = Ids_new;
    }
    
    Idr_i = Idr_i_new; 
    Fids = Fids_new; 
    Iqr_i = Iqr_i_new; 
    Fiqs = Fiqs_new; 
    Iqs = Iqs_new; 
    Ids = Ids_new;*/
    
    ddtFdr_i = -Rr*Idr_i + S*idtFqr.read(); 
    ddtFqr_i = -Rr*Iqr_i - S*idtFdr.read(); 
    power = Vds * (Ids - Iqs) + Vqs * (Ids + Iqs); 
	if(power<0)
	cout<<"Generated power is less than zero!"<<endl;

    
//     printf("S: %lf\n",S); 
//     printf("Fiqs: %lf\n",Fiqs); 
//     
//     printf("Ids: %lf\n",Ids); 
//     printf("Iqs: %lf\n",Iqs); 
// 
//     printf("idtFqr: %lf\n",idtFqr.read()); 
//     printf("idtFdr: %lf\n",idtFdr.read()); 
//     printf("Wg: %lf\n",Wg.read()); 
//     printf("Idr_i: %lf\n",Idr_i); 
//     printf("Fids: %lf\n",Fids); 
//     printf("Iqr_i: %lf\n",Iqr_i); 
//     printf("power: %lf\n",power); 
//     printf("ddtFdr_i: %lf\n",ddtFdr_i); 
//     printf("ddtFqr_i: %lf\n",ddtFqr_i); 
// 
//     sc_stop();
    
  }
  
  sS.write(S); 
  sIds.write(Ids);   
  sIqs.write(Iqs); 
  sIdr_i.write(Idr_i); 
  sIqr_i.write(Iqr_i); 
  sddtFdr_i.write(ddtFdr_i); 
  sddtFqr_i.write(ddtFqr_i); 
  sFiqs.write(Fiqs); 
  sFids.write(Fids); 
  
  Idr.write(Idr_i); 
  Iqr.write(Iqr_i); 
  ddtFdr.write(ddtFdr_i); 
  ddtFqr.write(ddtFqr_i); 
  P.write(power*0.15); 
  I.write(power/voltage);   
}
