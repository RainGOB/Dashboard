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
			
			racingCarData.batCur = (canData[0] + canData[1] * 256) / 10 - 1000;
			racingCarData.batLevel = canData[2];
			racingCarData.batVol = (canData[3] + canData[4] * 256) / 10;
			racingCarData.batAlarm = canData[5] >> 4;
			racingCarData.gearMode = canData[5] & 0x03;
			racingCarData.LbatAlr = (canData[5] >> 2) & 0x01;
			racingCarData.carMode = canData[6];
			racingCarData.angle = canData[0] - 90;		
			break;	
		
		case 0x214:
			racingCarData.lmcu_dccur = (canData[1] + canData[0] * 256) * 0.1 -1600;
			racingCarData.rmcu_dccur = (canData[3] + canData[2] * 256) * 0.1 -1600;
			racingCarData.lmcu_accur = (canData[5] + canData[4] * 256) * 0.1 -1600;
			racingCarData.rmcu_accur = (canData[7] + canData[6] * 256) * 0.1 -1600;
			break;
	
		case 0x50:
			racingCarData.sensor_diff = canData[1];
		
			if(racingCarData.sensor_diff == 0x51){
			//ACC_X = canData[2] + canData[1] * 256;
			//ACC_Y = canData[3] + canData[3] * 256;
			//ACC_Z = canData[4] + canData[5] * 256;
				racingCarData.acc_x = ((int16_t)(canData[2] | canData[3] << 8))  / 32768.0f * 16.0f;
				racingCarData.acc_y = ((int16_t)(canData[4] | canData[5] << 8))  / 32768.0f * 16.0f;
				racingCarData.acc_z = ((int16_t)(canData[6] | canData[7] << 8)) / 32768.0f * 16.0f;
				accsencordata[0] = canData[2];accsencordata[1] = canData[3];
				accsencordata[2] = canData[4];accsencordata[3] = canData[5];
				accsencordata[4] = canData[6];accsencordata[5] = canData[7];
			}
			else if(racingCarData.sensor_diff == 0x53){
				racingCarData.roll = ((int16_t)(canData[2] | canData[3] << 8)) / 32768.0 * 180.0;
				racingCarData.pitch = ((int16_t)(canData[4] | canData[5] << 8)) / 32768.0 * 180.0;
				racingCarData.yaw = ((int16_t)(canData[6] | canData[7] << 8)) / 32768.0 * 180.0;
				accsencordata[6] = canData[6];accsencordata[7] = canData[7];
			}
		    //racingCarData.angle = canData[6];
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

void acc_sencorCansend(){
	
	CAN2_Send(0x156,accsencordata);
}
