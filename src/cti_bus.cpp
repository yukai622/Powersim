#include "cti_bus.h"

void cti_bus::set_attributes(){
	Ibatt_cnv.set_delay(1);
	Vbatt_cnv.set_delay(1);
	Vpv_cnv.set_delay(1);
	Vwind_inv.set_delay(1);
}

void cti_bus::initialize(){

}

void cti_bus::processing(){
	Vbatt_cnv.write(vref_cti);
	Vpv_cnv.write(vref_cti);
	Vwind_inv.write(vref_cti);

	// Determine charge or discharge battery
	Ibatt_tmp = (Pload.read() - (Ipv_cnv.read()*vref_cti) - (Iwind_inv.read()*vref_cti))/vref_cti;
//	cout<<Ibatt_tmp<<endl;
	if(Ibatt_tmp > 0){
		Ibatt_cnv.write(0.0001);
	}else{
		Ibatt_cnv.write(0.0001);
	//	Ibatt_cnv.write(0.1);
	}

}
