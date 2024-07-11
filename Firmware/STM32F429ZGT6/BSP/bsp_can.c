#include "BSP_CAN.h"
#include "cmsis_os.h"

extern osEventFlagsId_t Upld_data_eventHandle;
uint32_t CAN_MailBox0;
uint8_t data[8] = {1,2,3,4,5,6,7,8};

void CanFilter_Config()
{
	CAN_FilterTypeDef Can_FilterStructure;
	
	Can_FilterStructure.FilterBank = 10;
	Can_FilterStructure.FilterMode = CAN_FILTERMODE_IDMASK;
	Can_FilterStructure.FilterScale = CAN_FILTERSCALE_32BIT;
    Can_FilterStructure.FilterIdHigh = (0x210 << 3)>>16;			//32位下，存储要过滤ID的高16位
    Can_FilterStructure.FilterIdLow = (0x210<<3)|(0x01<<2)|(0x00<<1);					//32位下，存储要过滤ID的低16位
    Can_FilterStructure.FilterMaskIdHigh = (0xFFC<<3)>>16;			//掩码模式下，存储的是掩码
    Can_FilterStructure.FilterMaskIdLow = (0xFFC<<3)|(0x01<<2)|(0x01<<1);
	Can_FilterStructure.FilterFIFOAssignment = 0;       //储存在哪一个fifo
	Can_FilterStructure.FilterActivation = ENABLE; //激活can
	Can_FilterStructure.SlaveStartFilterBank = 0;
	
	if(HAL_CAN_ConfigFilter(&hcan2,&Can_FilterStructure) != HAL_OK){
		//带输出状态
		Error_Handler();
	}
	//带输出状态
}

//can初始化
void canfilter_init(){
	
	CanFilter_Config();
	
	if(HAL_CAN_Start(&hcan2) != HAL_OK){
		//
		Error_Handler();
	}
	//
	
	if(HAL_CAN_ActivateNotification(&hcan2, CAN_IT_RX_FIFO0_MSG_PENDING) != HAL_OK){
		//
		Error_Handler();
	}
}

//发送函数
void CAN2_Send(uint32_t CAN_ID,uint8_t *CAN_Data){
	TxBuff.IDE = CAN_ID_EXT;
	TxBuff.ExtId = CAN_ID;
	TxBuff.RTR = CAN_RTR_DATA;  //设置传送的数据帧
	TxBuff.DLC = 8;            //数据长度
	
	if(HAL_CAN_AddTxMessage(&hcan2,&TxBuff,CAN_Data,&CAN_MailBox0) != HAL_OK){
		//
		Error_Handler();
	}

	//
}


void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *hcan){
	uint8_t  mdata[8];
	HAL_StatusTypeDef	status;
	
	
	if (hcan == &hcan2) {	
		
		status = HAL_CAN_GetRxMessage(hcan, CAN_RX_FIFO0, &RxBuff, mdata);
		
		if(HAL_OK == status){
			decode(RxBuff.ExtId,mdata);
			
			osEventFlagsSet(Upld_data_eventHandle,0x0f);  //0000 1111  事件标志位
		}
	}
}
