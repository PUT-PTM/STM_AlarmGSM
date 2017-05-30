#include "init.h"

/*
 * ===TODO==============================================
 * Czujnik IR - Dostosowac opoznienia
 * Kontaktron - Dokonczyc obsluge
 * Interfejs GSM
 * =====================================================
*/

<<<<<<< HEAD
=======
// VARIABLES //
unsigned int audio=0;
extern const u8 rawAudio[96078];
void TIM4_IRQHandler(void)
{

         	if(TIM_GetITStatus(TIM4, TIM_IT_Update) != RESET)
         	{

         		DAC_SetChannel1Data(DAC_Align_12b_R, rawAudio[audio]);
         		         	if(++audio>96077)audio=0;
         		             TIM_ClearITPendingBit(TIM4, TIM_IT_Update);
         	}
}

>>>>>>> 7c806cb2996f824becf1c0105395c851b71b2878
int main(void)
{
	SystemInit();
	setup(); //  GPIO, UART, ADC, EXTI, TIM, Delay
	alarmloop(); // Main loop
}
