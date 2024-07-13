#include "APP_CAN.h"
#include "ui.h"

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
			racingCarData.LbatAlr = canData[7];
			break;	
		
		case 0x214:
			ACC_X = canData[0] + canData[1] * 256;
			ACC_Y = canData[2] + canData[3] * 256;
			ACC_Z = canData[4] + canData[5] * 256;
			racingCarData.acc_x = ((float)ACC_X / 32768.0f) * 16.0f;
			racingCarData.acc_y = ((float)ACC_Y / 32768.0f) * 16.0f;
		    racingCarData.acc_z = ((float)ACC_Z / 32768.0f) * 16.0f;
		    racingCarData.angle = canData[6];
			break;
	}
}

void keyControlCanSend()
{
	KeyControlData[0] = 000;
	if(HAL_GPIO_ReadPin(INPUT2_GPIO_Port, INPUT2_Pin) == RESET) KeyControlData[0] |= 0x01 << 1;
	if(HAL_GPIO_ReadPin(INPUT3_GPIO_Port, INPUT3_Pin) == RESET) KeyControlData[0] |= 0x01 << 2;
	if(HAL_GPIO_ReadPin(INPUT4_GPIO_Port, INPUT4_Pin) == RESET) KeyControlData[0] |= 0x01 << 3;
	
	CAN2_Send(0X155, KeyControlData);
}
