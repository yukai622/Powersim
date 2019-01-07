#include "systemc-ams.h"

SCA_TDF_MODULE (turbine)
{
  sca_tdf::sca_out<double> I, V, Pm, Pe, T; 
  sca_tdf::sca_in<double> wind; 

  SCA_CTOR(turbine): I("I"), V("V"), Pm("Pm"), Pe("Pe"), T("T"), wind("wind") {}

  void set_attributes();

  void initialize();

  void processing();
  
private: 
  
  double ro; // air density
  double beta; // blade pitch angle
  double lambda, lambda_i; // tip speed ratio
  double radius; // blade radius
  double Cp; // Betz factor 
  double Ct; // torque coefficient
  double c1, c2, c3, c4, c5, c6; // coefficients for Cp
  double PI; // greek Pi
  double torque; // torque
  double w; // angular speed
  double n; // rotational speed r/min
};
