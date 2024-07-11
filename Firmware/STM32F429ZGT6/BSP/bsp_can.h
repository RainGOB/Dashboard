#ifndef _BSP_CAN_H_
#define _BSP_CAN_H_

#include "main.h"
#include "can.h"
#include "app_can.h"

static CAN_TxHeaderTypeDef TxBuff;    //can������Ϣ����Ϣͷ
static CAN_RxHeaderTypeDef RxBuff;    //can������Ϣ����Ϣͷ


void CanFilter_Config(void);
void canfilter_init(void);
void CAN2_Send(uint32_t CAN_ID,uint8_t *CAN_Data);
void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *hcan);

#define GUI_UPDATE_EVENT (0x01) //�����¼���־λ0��

#endif
