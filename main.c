#include "init.h"
#include "usart.h"
//TODO:
//czujnik IR
//kontaktron
//glosnik
//interfejs GSM
//usart ->GSM
//
//interfejs do wszystkiego kurwa
//


int main(void)
{
	SystemInit();
	ustaw();

	for(;;)
	{
		while(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0)==1)
		{
				GPIO_SetBits(GPIOD, GPIO_Pin_12);
				usart1();

		}
		GPIO_ResetBits(GPIOD, GPIO_Pin_12);

	}


}
