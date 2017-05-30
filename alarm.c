#include "alarm.h"

void EXTI0_IRQHandler(void)
{
        if(EXTI_GetITStatus(EXTI_Line0) != RESET)
       	{
         	GPIO_ToggleBits(GPIOD, GPIO_Pin_15);
         	EXTI_ClearITPendingBit(EXTI_Line0);
   	   	}
}


void Power()
{
	if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_7)==1) IsAlarmOn=false;
	else IsAlarmOn=true;
}

void alarmloop()
{
	for(;;)
	{

		while(IsAlarmOn)
		{
			movesensor();
			//Delayms(500);
			magneticsensor();
		}
		GPIO_ToggleBits(GPIOD, GPIO_Pin_14);
		Delayms(500);

	}
}
