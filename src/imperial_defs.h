#ifndef _IMPERIAL_DEFS_
#define _IMPERIAL_DEFS_

// timestep 
#define TIMESTEP 0.001, sc_core::SC_SEC

// voltage
#define voltage 12

// blade angle
#define beta   0

// aerodynamic coefficients
#define c1     0.5
#define c2     116
#define c3     0.4
#define c4     0
#define c5     5
#define c6     21
#define ro0    1.225
// #define H    

// rotor radius
#define radius 25 

// greek pi 
# define PI     3.1416

// K - stiffness
#define stiffness 60000000

// n - gear ratio
#define gear_ratio 65.2700

// D - damping
#define damping 1000000

// rotor inertia
#define Hm 1600000

// generator inertia
#define Hg 35.1840

// reference voltages
#define Vds 1000
#define Vqs 1000

// Rs - stator resistance
#define Rs 0.0121

// Xs - stator reactance
#define Xs 2.7626

// Rr - rotor resistance
#define Rr 0.0080

// Xr - rotor reactance
#define Xr 0.1761

// ws - synchronous speed 
#define synch_speed  1

// Xm - mutual reactance
#define Xm 2.7626

#endif
