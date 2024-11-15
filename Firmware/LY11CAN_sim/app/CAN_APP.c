#include "CAN_APP.h"
#include "string.h"

#define  SPEED_RATIO  4 	//主减速比
#define  PI  3.14	       	//圆周率
#define  WHEEL_R  0.2286	   	//车轮半径
#define  NUM_OF_TEETH 20.0    //码盘齿数

uint8_t Gear_Receive;
uint8_t upSpeedFlag = 1;
uint8_t batlevelFlag = 1;
uint8_t uploadFlag = 0;
uint8_t accFlag = 1;
struct RacingCarData racingCarData;
uint32_t CAN_TX_BOX1;

void CANFilter_Config(void)//无论发啥我都照单全收。
{
    CAN_FilterTypeDef  sFilterConfig;
    
    sFilterConfig.FilterBank = 10;                       //CAN过滤器编号，范围0-27
    sFilterConfig.FilterMode = CAN_FILTERMODE_IDMASK;   //CAN过滤器模式，掩码模式或列表模式
    sFilterConfig.FilterScale = CAN_FILTERSCALE_32BIT;  //CAN过滤器尺度，16位或32位
    sFilterConfig.FilterIdHigh = 0x000 << 5;			//32位下，存储要过滤ID的高16位
    sFilterConfig.FilterIdLow = 0x0000;					//32位下，存储要过滤ID的低16位
    sFilterConfig.FilterMaskIdHigh = 0x0000;			//掩码模式下，存储的是掩码
    sFilterConfig.FilterMaskIdLow = 0x0000;
    sFilterConfig.FilterFIFOAssignment = 0;				//报文通过过滤器的匹配后，存储到哪个FIFO
    sFilterConfig.FilterActivation = ENABLE;    		//激活过滤器
    sFilterConfig.SlaveStartFilterBank = 0;
    
    if (HAL_CAN_ConfigFilter(&hcan, &sFilterConfig) != HAL_OK) {
        printf("CAN Filter Config Fail!\r\n");
        Error_Handler();
    }
    printf("CAN Filter Config Success!\r\n");

}



void CAN1_Send(uint32_t CAN_ID, uint8_t *CAN_DATA)
{
	//uint8_t data[4] = {0x01, 0x02, 0x03, 0x04};
    
  TxMessage.IDE = CAN_ID_EXT;     //设置ID类型
	TxMessage.ExtId = CAN_ID;        //设置ID号
  TxMessage.RTR = CAN_RTR_DATA;   //设置传送数据帧
	TxMessage.DLC = 8;              //设置数据长度
    
	if (HAL_CAN_AddTxMessage(&hcan, &TxMessage, CAN_DATA, &CAN_TX_BOX1) != HAL_OK) {
        printf("CAN send test data fail!\r\n");
        Error_Handler();
    }
    printf("CAN send test data success!\r\n");
		
}
void CanFilterInit()
{
	//usartTxFlag = 1;
	printf("----- CAN Test Board #1 -----\r\n");
	CANFilter_Config();
    
    /* 2. CAN Start */
	if (HAL_CAN_Start(&hcan) != HAL_OK) {
			printf("CAN Start Fail\r\n");
			Error_Handler();
	}
	printf("CAN Start Success\r\n");
	
	/* 3. Enable CAN RX Interrupt */
	if (HAL_CAN_ActivateNotification(&hcan, CAN_IT_RX_FIFO0_MSG_PENDING) != HAL_OK) {
			printf("CAN_IT_RX_FIFO0_MSG_PENDING Enable Fail\r\n");
			Error_Handler();
	}
	printf("CAN_IT_RX_FIFO0_MSG_PENDING Enable Success\r\n");
}

/*
struct RacingCarData
{

	//ID:0X193
	uint8_t FrontSpeed;          //前轮车速 在这里作为参考车速 1Byte
	uint8_t PedalTravel;         //油门踏板开度    1Byte
	uint8_t brakeTravel;         //刹车踏板开度    1Byte
	uint8_t carTravel;           //车辆跑动距离    1Byte
	uint16_t l_motor_torque;      //左电机目标转矩  2Byte
  uint16_t r_motor_torque;      //右电机目标转矩  2Byte

	//ID:0X196 
	uint8_t batAlarm;            //电池告警  0~4 无告警：0 一级告警：1（最严重） 二级告警：2 三级告警：3
	uint8_t batTemp;               //电池温度  0-160  offset:-40
	uint8_t batLevel;            //电池电量  0-100
	uint16_t batVol;              //电池电压  0-900
	uint8_t gearMode;            //挡位信息  1Bit
	uint8_t carMode;             //车辆运行模式  1Bit 1:转矩模式 2：速度模式
	//ID:0X191
	uint16_t lmotorSpeed;         //左电机转速  2Bit offset -10000rpm 分辨率:0.5
	//ID:0X192
	uint8_t lmotorTemp;          //左电机温度   1Byte 0~150摄氏度 offset:-50
	uint8_t mcu1Temp;            //电机控制器1温度 1Byte 0~150摄氏度 offset:-50
	//ID:0X194	
	uint16_t rmotorSpeed;         //右电机转速  2Bit offset -10000rpm 分辨率:0.5
	//ID:0X195
	uint8_t rmotorTemp;          //右电机温度
	uint8_t mcu2Temp;            //电机控制器2温度
	
	
};
*/


#if Transmitter
void carDataUpdate()//模拟汽车跑动数据
{
	//ID:0X196
	racingCarData.carMode = 2;//速度模式
	racingCarData.batTemp = 40;//电池温度 40摄氏度
	racingCarData.batVol = 450;//动力电池电压450V
	racingCarData.batAlarm = 0;//无告警

	//ID:0X191
	if(upSpeedFlag)
	{
		racingCarData.lmotorSpeed+=100;         //左电机转速  2Bit offset -10000rpm 分辨率:0.5	
		racingCarData.angle += 4;
		if(racingCarData.lmotorSpeed == 5500)
			upSpeedFlag = 0;
	}
	else
	{
		racingCarData.lmotorSpeed-=100;
		racingCarData.angle -= 4;
		if(racingCarData.lmotorSpeed == 0)
			upSpeedFlag = 1;
	}
	//ID:0X194
	racingCarData.rmotorSpeed = racingCarData.lmotorSpeed;
	
	//	//ID:0X193
//	uint8_t FrontSpeed;          //前轮车速 在这里作为参考车速 1Byte
//	uint8_t PedalTravel;         //油门踏板开度    1Byte
//	uint8_t brakeTravel;         //刹车踏板开度    1Byte
//	uint8_t carTravel;           //车辆跑动距离    1Byte
//	uint16_t l_motor_torque      //左电机目标转矩  2Byte
//  uint16_t r_motor_torque      //右电机目标转矩  2Byte
	//ID:0X193
	racingCarData.FrontSpeed = (int)(racingCarData.lmotorSpeed/SPEED_RATIO*PI*2*WHEEL_R*3.6/60);  //由转速换算为车速
	if(upSpeedFlag)
	{
		racingCarData.l_motor_torque = 1000;
		racingCarData.r_motor_torque = racingCarData.l_motor_torque;
		racingCarData.PedalTravel = 100; //油门踏板开度为100 踩死
		racingCarData.brakeTravel = 0;
		racingCarData.LbatAlr = 0;
	}
		
	else
	{
		racingCarData.l_motor_torque = 0;
		racingCarData.r_motor_torque = racingCarData.l_motor_torque;
		racingCarData.PedalTravel =0;
		racingCarData.brakeTravel = 40;
		racingCarData.LbatAlr = 1;
	}
	
	if(batlevelFlag)
	{
		racingCarData.batLevel += 1;
		if(racingCarData.batLevel >= 90)
			batlevelFlag = 0;
	}
	else
	{
		racingCarData.batLevel -= 1;

		if(racingCarData.batLevel <= 10)
			batlevelFlag = 1;
	}
	
	if(accFlag){
		racingCarData.acc_x += 0x10;
		racingCarData.acc_y += 0x10;
		racingCarData.acc_z += 0x10;
		if(racingCarData.acc_x >= 0xB000)
			accFlag = 0;
	}
	else{
		racingCarData.acc_x -= 0x10;
		racingCarData.acc_y -= 0x10;
		racingCarData.acc_z -= 0x10;
		if(racingCarData.acc_x <= 5000)
			accFlag = 1;
	}
	
	if(Gear_Receive == 2){
		racingCarData.gearMode += 1;
		if(racingCarData.gearMode == 5) 
			racingCarData.gearMode = 0;
	}
	
	racingCarData.carTravel+=5;
	
	//ID:0X192
	racingCarData.lmotorTemp = 40; //左电机温度   1Byte 0~150摄氏度 offset:-50
	racingCarData.mcu1Temp = 40;   //电机控制器1温度 1Byte 0~150摄氏度 offset:-50
	//ID:0X195
	racingCarData.rmotorTemp = 40; //右电机温度   1Byte 0~150摄氏度 offset:-50
	racingCarData.mcu2Temp = 40;   //电机控制器2温度 1Byte 0~150摄氏度 offset:-50
	
	canDataPack();
}
//按照CAN协议打包要发送的行车数据
void canDataPack()
{
	//ID:0X212
	uint8_t carData[8];
	//	LeftMotorRPM = (CAN_Re_0_M06[0] + CAN_Re_0_M06[1]*256)/2 - 10000;
	carData[0] = ((racingCarData.lmotorSpeed + 10000) * 2) % 256; //转速 低八位
	carData[1] = ((racingCarData.lmotorSpeed + 10000) * 2) >> 8;  //转速 高八位

	//	LeftMotorRPM = (CAN_Re_0_M06[0] + CAN_Re_0_M06[1]*256)/2 - 10000;
	carData[4] = ((racingCarData.rmotorSpeed + 10000) * 2) % 256; //转速 低八位
	carData[5] = ((racingCarData.rmotorSpeed + 10000) * 2) >> 8;  //转速 高八位
	 
	carData[2] = racingCarData.lmotorTemp + 50;//左电机温度   1Byte 0~150摄氏度 offset:-50
	carData[3] = racingCarData.mcu1Temp + 50;  //电机控制器1温度 1Byte 0~150摄氏度 offset:-50
	
	carData[6] = racingCarData.rmotorTemp + 50;//右电机温度   1Byte 0~150摄氏度 offset:-50
	carData[7] = racingCarData.mcu2Temp + 50;  //电机控制器温度 1Byte 0~150摄氏度 offset:-50
	CAN1_Send(0X212, carData);
	memset(carData,0x00,sizeof(carData)); //清空数组
	        
	//ID:0X213
	carData[0] = racingCarData.batAlarm;//电池告警  0~4 无告警：0 一级告警：1（最严重） 二级告警：2 三级告警：3
	carData[1] = racingCarData.batTemp + 40;//电池温度  0-160  offset:-40
	carData[2] = racingCarData.batLevel;//电池电量  0-100
	carData[5] = racingCarData.gearMode;//挡位信息  1Bit
	carData[6] = racingCarData.carMode;//车辆运行模式  1Bit 1:转矩模式 2：速度模式
	carData[4] = racingCarData.batVol * 10 % 256;//电池电压  0-900 Resolution = 0.1 LSB在后八位
	carData[3] = racingCarData.batVol * 10 >> 8;
	carData[7] = racingCarData.LbatAlr;
	CAN1_Send(0X213, carData);
	memset(carData,0x00,sizeof(carData)); //清空数组
	
	//ID:0X211
	carData[0] = racingCarData.FrontSpeed;
	carData[1] = racingCarData.PedalTravel;
	carData[2] = racingCarData.brakeTravel;
	carData[3] = racingCarData.carTravel;
	carData[4] = racingCarData.l_motor_torque % 256;
	carData[5] = racingCarData.l_motor_torque >> 8;
	carData[6] = racingCarData.r_motor_torque % 256;
	carData[7] = racingCarData.r_motor_torque >> 8;
	CAN1_Send(0X211, carData);
	memset(carData,0x00,sizeof(carData)); //清空数组
	
	HAL_Delay(200);
	//ID:0x214
	carData[0] = (int)(racingCarData.acc_x) % 256;   //加速度XLSB
	carData[1] = (int)(racingCarData.acc_x) >> 8;	  //加速度XMSB
	carData[2] = (int)(racingCarData.acc_y) % 256;   //加速度YLSB
	carData[3] = (int)(racingCarData.acc_y) >> 8;    //加速度XMSB
	carData[4] = (int)(racingCarData.acc_z) % 256;   //加速度ZLSB
	carData[5] = (int)(racingCarData.acc_z) >> 8;    //加速度ZMSB
	carData[6] = racingCarData.angle;
	CAN1_Send(0x214, carData);
	memset(carData,0x00,sizeof(carData)); //清空数组
	memset(carData,0x00,sizeof(carData)); //清空数组
}
#endif

#if Receiver


void decodeCanData(uint32_t canID, uint8_t *canData)
{
	switch(canID)
	{
		case 0x155:
			Gear_Receive =canData[0];
			break;
	}	
}

/***接收函数***/
void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *hcan1)
{
	uint8_t  data[8];
	HAL_StatusTypeDef	status;
	
	if (hcan1 == &hcan) {	

		status = HAL_CAN_GetRxMessage(hcan1, CAN_RX_FIFO0, &RxMessage, data);

		if (HAL_OK == status){   
		#if Receiver
			decodeCanData(RxMessage.ExtId, data);
			uploadFlag = 1;
		#endif
//			printf("--->Data Receieve!\r\n");
//			printf("RxMessage.StdId is %#x\r\n",  RxMessage.StdId);
//			printf("data[0] is 0x%02x\r\n", data[0]);
//			printf("data[1] is 0x%02x\r\n", data[1]);
//			printf("data[2] is 0x%02x\r\n", data[2]);
//			printf("data[3] is 0x%02x\r\n", data[3]);
//			printf("<---\r\n");  
		}
	}
}

#endif
