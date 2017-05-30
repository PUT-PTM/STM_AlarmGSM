#include "init.h"

/*
 * ===TODO==============================================
 * Czujnik IR - Dostosowac opoznienia/odswiezenie
 * Kontaktron - Dokonczyc obsluge
 * Audio - Zmienic dzwiek alarmu, Puszczac od nowa
 * Zablokowac Alarm po wykryciu
 * Interfejs GSM
 * =====================================================
*/

// VARIABLES //
unsigned int audio=0;
extern const u8 rawAudio[123200];
void TIM4_IRQHandler(void)
{

         	if(TIM_GetITStatus(TIM4, TIM_IT_Update) != RESET)
         	{

         		DAC_SetChannel1Data(DAC_Align_12b_R, rawAudio[audio]);
         		         	if(++audio>123199)audio=0;
         		             TIM_ClearITPendingBit(TIM4, TIM_IT_Update);
         	}
}

int main(void)
{
	SystemInit();
	ustaw();
	alarmloop();
}
