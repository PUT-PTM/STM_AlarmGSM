#include "init.h"
void movesensor()
{
	while(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_0)==1)
					{
							TIM_Cmd(TIM4, ENABLE);
							GPIO_SetBits(GPIOD, GPIO_Pin_12);
					}
					GPIO_ResetBits(GPIOD, GPIO_Pin_12);
					TIM_Cmd(TIM4, DISABLE);

}
