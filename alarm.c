#include "alarm.h"

void EXTI0_IRQHandler(void) // PA0 push button
{
        if(EXTI_GetITStatus(EXTI_Line0) != RESET)
       	{
			TIM_Cmd(TIM3, DISABLE); // Counter Off
			TIM_Cmd(TIM4, DISABLE); // Audio Off
			clockon=false;
			alarmring = false; // Audio Off
        	counter=0; // Binary Counter
			lightoff(12);
			lightoff(13);
			lightoff(14);
			lightoff(15);
         	Power();
         	Delayms(100);
         	EXTI_ClearITPendingBit(EXTI_Line0);
   	   	}
}

void TIM3_IRQHandler(void)
{
         	if(TIM_GetITStatus(TIM3, TIM_IT_Update) != RESET)
         	{
         		binaryclock(counter);
         		if(++counter>8)counter=0;
                TIM_ClearITPendingBit(TIM3, TIM_IT_Update);
         	}
}

void TIM4_IRQHandler(void)
{
         	if(TIM_GetITStatus(TIM4, TIM_IT_Update) != RESET)
         	{

         		DAC_SetChannel1Data(DAC_Align_12b_R, rawAudio[audio]);
         		if(++audio>96077) audio=0;
         		TIM_ClearITPendingBit(TIM4, TIM_IT_Update);
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
			if(clockon==false && alarmring==false)
			{
				Delayms(1500);
				GPIO_ToggleBits(GPIOD, GPIO_Pin_12);
				lightoff(14);
			}
			if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_0)==1 && clockon==false && alarmring==false)
					{
						clockon=true;
						lightoff(12);
						TIM_Cmd(TIM3, ENABLE);
					}
		}

		else
		{
			lightoff(12);
			GPIO_ToggleBits(GPIOD, GPIO_Pin_14);
			Delayms(500);
		}
	}
}

void binaryclock(int counter)
{
	switch(counter)
		{
			case 0:
				{
					lightoff(12);
					lightoff(13);
					lightoff(14);
					lightoff(15);
				}break;
			case 1:
				{
					lighton(12);
				}break;
			case 2:
				{
					lightoff(12);
					lighton(13);
				}break;
			case 3:
				{
					lighton(12);
				}break;
			case 4:
				{
					lightoff(12);
					lightoff(13);
					lighton(14); //4 sec
				}break;
			case 5:
				{
					lighton(12);
				}break;
			case 6:
				{
					lightoff(12);
					lighton(13);
				}break;
			case 7:
				{
					lighton(12);
				}break;
			case 8:
				{
					lightoff(12);
					lightoff(13);
					lightoff(14);
					lighton(15);
					TIM_Cmd(TIM3, DISABLE);
					clockon=false;
					alarm();
				}break;
		}
}

void alarm()
{
	alarmring=true;
	TIM_Cmd(TIM3, DISABLE);
	counter=0;
	lightoff(12);
	lightoff(13);
	lightoff(14);
	lightoff(15);
	clockon=false;
	TIM_Cmd(TIM4, ENABLE);
}
