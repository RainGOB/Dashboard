#include "APP_CAN.h"


void decode(uint32_t ID,uint8_t *canData){
	switch(ID){
		case 0x211:
			racingCarData.FrontSpeed = canData[0];
			racingCarData.PedalTravel = canData[1];
			racingCarData.brakeTravel = canData[2];
			racingCarData.carTravel = canData[3];
			racingCarData.l_motor_torque = canData[4] + canData[5] * 256;
			racingCarData.r_motor_torque = canData[6] + canData[7] * 256;
			break;
		
		case 0x212:
			racingCarData.lmotorSpeed = (canData[0] + canData[1]*256)/2 - 10000;
			racingCarData.lmotorTemp = canData[2] - 50;
			racingCarData.mcu1Temp = canData[3] - 50;
			racingCarData.rmotorSpeed = (canData[4] + canData[5]*256)/2 - 10000;
			racingCarData.rmotorTemp = canData[6] - 50;
			racingCarData.mcu2Temp = canData[7] - 50;
			break;
		
		case 0x213:
			racingCarData.batAlarm = canData[0];
			racingCarData.batTemp = canData[1] - 40;
			racingCarData.batLevel = canData[2];
			racingCarData.batVol = (canData[3] + canData[4] * 256) / 10;
			racingCarData.gearMode = canData[5];
			racingCarData.carMode = canData[6];
			data[4] = canData[4];
			break;	

	}
}
