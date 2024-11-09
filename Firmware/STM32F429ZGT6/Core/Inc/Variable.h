#ifndef _VARIABLE_H_
#define _VARIABLE_H_

#include "main.h"

#define RXBUFFERSIZE  100    //�������ֽ���
#define RESPONSEWAITING 500

extern uint8_t Rx_buff;
extern char Rx_string[RXBUFFERSIZE];
extern uint8_t Rx_Count;
extern uint8_t Tx_Flag;
extern uint8_t IRQ_JudgEnable;
extern uint8_t CANOK_Flag;
extern uint8_t KeyControlData[8];
extern uint8_t accsencordata[8];

extern uint8_t EC200_RdyFlag;
extern uint8_t MQTTClient_RdyFlag;
extern uint8_t PUBOK_Flag;

extern uint8_t QMTOPEN_Flag;
extern uint8_t QMTCONN_Flag;
extern uint8_t QMTCFG_Flag;

struct RacingCarData{
	//ID:0X211
	uint8_t FrontSpeed;          //ǰ�ֳ��� ��������Ϊ�ο����� 1Byte
	uint8_t PedalTravel;         //����̤�忪��    1Byte
	uint8_t brakeTravel;         //ɲ��̤�忪��    1Byte
	uint8_t carTravel;           //�����ܶ�����    1Byte
	uint16_t l_motor_torque;      //����Ŀ��ת��  2Byte
	uint16_t r_motor_torque;      //�ҵ��Ŀ��ת��  2Byte

	//ID:0X213
	uint8_t batAlarm;            //��ظ澯  0~4 �޸澯��0 һ���澯��1�������أ� �����澯��2 �����澯��3
	float batCur;               //��ص���  -1000~+1000  offset:-1000
	uint8_t batLevel;            //��ص���  0-100
	uint16_t batVol;              //��ص�ѹ  0-900
	uint8_t gearMode;            //��λ��Ϣ  1Bit
	uint8_t carMode;             //��������ģʽ  1Bit 1:ת��ģʽ 2���ٶ�ģʽ
	uint8_t LbatAlr;			//��ѹ��ر���λ 0-1

	//ID:0X212
	uint16_t lmotorSpeed;         //����ת��  2Bit offset -10000rpm �ֱ���:0.5
	uint8_t lmotorTemp;          //�����¶�   1Byte 0~150���϶� offset:-50
	uint8_t mcu1Temp;            //���������1�¶� 1Byte 0~150���϶� offset:-50
	uint16_t rmotorSpeed;         //�ҵ��ת��  2Bit offset -10000rpm �ֱ���:0.5
	uint8_t rmotorTemp;          //�ҵ���¶�
	uint8_t mcu2Temp;  
		
	//ID:0x214
	uint16_t lmcu_dccur;
	uint16_t rmcu_dccur;
	uint16_t lmcu_accur;
	uint16_t rmcu_accur;
		
	//ID:0x204
	uint8_t sensor_diff;
	float acc_x;
	float acc_y;
	float acc_z;
	float yaw;
	float pitch;
	float roll;
	float angle;
};

extern struct RacingCarData racingCarData;

extern uint16_t *lcd_fb;

extern uint8_t TB_State;
extern uint8_t TBSA_Flag;
extern uint8_t TBSO_Flag;

#endif
