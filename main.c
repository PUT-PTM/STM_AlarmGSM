#include "init.h"

/*
 * ===TODO==============================================
 * Czujnik IR - Dostosowac opoznienia
 * Kontaktron - Dokonczyc obsluge
 * Interfejs GSM
 * =====================================================
*/

int main(void)
{
	SystemInit();
	setup(); //  GPIO, UART, ADC, EXTI, TIM, Delay
	alarmloop(); // Main loop
}
