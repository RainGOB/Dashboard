#ifndef _VARIABLE_H_
#define _VARIABLE_H_

#include "main.h"

#define RXBUFFERSIZE  100    //最大接收字节数
#define RESPONSEWAITING 500

extern uint8_t Rx_buff;
extern char Rx_string[RXBUFFERSIZE];
extern uint8_t Rx_Count;
extern uint8_t Tx_Flag;
extern uint8_t IRQ_JudgEnable;
extern uint8_t CANOK_Flag;
extern uint8_t KeyControlData[8];

extern uint8_t EC200_RdyFlag;
extern uint8_t MQTTClient_RdyFlag;
extern uint8_t PUBOK_Flag;

extern uint8_t QMTOPEN_Flag;
extern uint8_t QMTCONN_Flag;
extern uint8_t QMTCFG_Flag;

extern int16_t ACC_X;
extern int16_t ACC_Y;
extern int16_t ACC_Z;

struct RacingCarData{
	//ID:0X211
	uint8_t FrontSpeed;          //前轮车速 在这里作为参考车速 1Byte
	uint8_t PedalTravel;         //油门踏板开度    1Byte
	uint8_t brakeTravel;         //刹车踏板开度    1Byte
	uint8_t carTravel;           //车辆跑动距离    1Byte
	uint16_t l_motor_torque;      //左电机目标转矩  2Byte
	uint16_t r_motor_torque;      //右电机目标转矩  2Byte

	//ID:0X213
	uint8_t batAlarm;            //电池告警  0~4 无告警：0 一级告警：1（最严重） 二级告警：2 三级告警：3
	uint8_t batTemp;               //电池温度  0-160  offset:-40
	uint8_t batLevel;            //电池电量  0-100
	uint16_t batVol;              //电池电压  0-900
	uint8_t gearMode;            //挡位信息  1Bit
	uint8_t carMode;             //车辆运行模式  1Bit 1:转矩模式 2：速度模式
	uint8_t LbatAlr;			//低压电池报警位 0-1

	//ID:0X212
	uint16_t lmotorSpeed;         //左电机转速  2Bit offset -10000rpm 分辨率:0.5
	uint8_t lmotorTemp;          //左电机温度   1Byte 0~150摄氏度 offset:-50
	uint8_t mcu1Temp;            //电机控制器1温度 1Byte 0~150摄氏度 offset:-50
	uint16_t rmotorSpeed;         //右电机转速  2Bit offset -10000rpm 分辨率:0.5
	uint8_t rmotorTemp;          //右电机温度
	uint8_t mcu2Temp;  
		
	//ID:0x204
	float acc_x;
	float acc_y;
	float acc_z;
	uint8_t angle;
};

extern struct RacingCarData racingCarData;

extern uint16_t *lcd_fb;

#endif
