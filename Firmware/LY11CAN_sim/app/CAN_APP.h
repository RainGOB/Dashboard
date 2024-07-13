
#ifndef __CAN_APP_H__
#define __CAN_APP_H__

#include "can.h"
#include "main.h"
#include "stdio.h"
#include "usart.h"


static CAN_TxHeaderTypeDef        TxMessage;    //CAN���͵���Ϣ����Ϣͷ
static CAN_RxHeaderTypeDef        RxMessage;    //CAN���յ���Ϣ����Ϣͷ

void CAN1_Send(uint32_t CAN_ID, uint8_t *CAN_DATA);

void CANFilter_Config(void);
void CanFilterInit(void);

#define Transmitter 1
#define Receiver    1
#if Transmitter
void carDataUpdate(void);
void canDataPack(void);
#endif

#if Receiver
void decodeCanData(uint32_t canID, uint8_t *canData);
#endif
struct RacingCarData
{
/*
	//ID:0X193
	uint8_t FrontSpeed;          //ǰ�ֳ��� ��������Ϊ�ο����� 1Byte
	uint8_t PedalTravel;         //����̤�忪��    1Byte
	uint8_t brakeTravel;         //ɲ��̤�忪��    1Byte
	uint8_t carTravel;           //�����ܶ�����    1Byte
	uint16_t l_motor_torque;     //����Ŀ��ת��  2Byte
  uint16_t r_motor_torque;     //�ҵ��Ŀ��ת��  2Byte

	//ID:0X196 
	uint8_t batAlarm;            //��ظ澯  0~4 �޸澯��0 һ���澯��1�������أ� �����澯��2 �����澯��3 1Byte
	uint8_t batTemp;             //����¶�  0-160  offset:-40  1Byte
	uint8_t batLevel;            //��ص���  0-100  1Byte
	uint16_t batVol;              //��ص�ѹ  0-900  2Byte
	uint8_t gearMode;            //��λ��Ϣ  1Bit   1Byte
	uint8_t carMode;             //��������ģʽ  1Bit
	//ID:0X191
	uint16_t lmotorSpeed;         //����ת��  2Bit offset -10000rpm �ֱ���:0.5
	//ID:0X192
	uint8_t lmotorTemp;          //�����¶�   1Byte 0~150���϶� offset:-50
	uint8_t mcu1Temp;            //���������1�¶� 1Byte 0~150���϶� offset:-50
	//ID:0X194	
	uint16_t rmotorSpeed;         //�ҵ��ת��  2Bit offset -10000rpm �ֱ���:0.5
	//ID:0X195
	uint8_t rmotorTemp;          //�ҵ���¶�
	uint8_t mcu2Temp;            //���������2�¶�
	*/
		//ID:0X211
	uint8_t FrontSpeed;          //ǰ�ֳ��� ��������Ϊ�ο����� 1Byte
	uint8_t PedalTravel;         //����̤�忪��    1Byte
	uint8_t brakeTravel;         //ɲ��̤�忪��    1Byte
	uint8_t carTravel;           //�����ܶ�����    1Byte
	uint16_t l_motor_torque;      //����Ŀ��ת��  2Byte
	uint16_t r_motor_torque;      //�ҵ��Ŀ��ת��  2Byte

	//ID:0X213
	uint8_t batAlarm;            //��ظ澯  0~4 �޸澯��0 һ���澯��1�������أ� �����澯��2 �����澯��3
	uint8_t batTemp;               //����¶�  0-160  offset:-40
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
	
	//ID:0x204
	uint16_t acc_x;            //���ٶ�X
	uint16_t acc_y;			   //���ٶ�y
	uint16_t acc_z;			   //���ٶ�z
	uint8_t angle;
};
extern struct RacingCarData racingCarData;
extern uint8_t uploadFlag;

#endif //__BSP_CAN_H__
