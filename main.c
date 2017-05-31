#include "init.h"

int main(void)
{
	SystemInit();
	setup(); //  GPIO, UART, ADC, EXTI, TIM, Delay
	alarmloop(); // Main loop
}
