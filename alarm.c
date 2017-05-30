#include "alarm.h"

void EXTI0_IRQHandler(void)
{
        if(EXTI_GetITStatus(EXTI_Line0) != RESET)
       	{
         	Power();
         	Delayms(100);
         	EXTI_ClearITPendingBit(EXTI_Line0);
   	   	}
}


void Power()
{
	if(IsAlarmOn) IsAlarmOn=false;
	else IsAlarmOn=true;
}


void alarmloop()
{
	for(;;)
	{
		if(IsAlarmOn)
		{
			Delayms(1500);
			lightoff(14);
			lighton(12);
			movesensor();
			magneticsensor();
		}
		else
		{
			lightoff(12);
			lighton(14);
			Delayms(500);
		}
	}
}

