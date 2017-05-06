#include "init.h"
int main(void)
{
	SystemInit();
	ustaw();

	for(;;)
	{
		while(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0)==1)
		{
				GPIO_SetBits(GPIOD, GPIO_Pin_12);

		}
		GPIO_ResetBits(GPIOD, GPIO_Pin_12);

	}

}
