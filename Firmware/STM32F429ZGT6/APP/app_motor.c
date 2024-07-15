#include "app_motor.h"


void TB6600_motion(void){
	if(KeyControlData[0] == 8){
		TBSA_Flag = 1;
		if(TBSO_Flag == 1){
		HAL_TIM_PWM_Start_IT(&htim9,TIM_CHANNEL_1);
		TBSO_Flag = 0;
		}
	}
	else{
		TBSO_Flag = 1;
		if(TBSA_Flag == 1){
			TB_State = 1-TB_State;
			
			HAL_TIM_PWM_Stop_IT(&htim9,TIM_CHANNEL_1);
			
			if(TB_State == 1) HAL_GPIO_WritePin(TB6600_DIR_GPIO_Port,TB6600_DIR_Pin,GPIO_PIN_SET);
	        else HAL_GPIO_WritePin(TB6600_DIR_GPIO_Port,TB6600_DIR_Pin,GPIO_PIN_RESET);
			
			TBSA_Flag = 0;
		}
	}
	

	
}
