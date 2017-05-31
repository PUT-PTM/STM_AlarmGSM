//#include "magneticsensor.h"
//int wyn=0;
//bool magneticsensor()
//{
//	wyn = ADC_GetConversionValue(ADC1);
//	if(wyn<500){
//		return true;
//	}
//	else {
//		return false;
//	}
//}

//void magneticsensor()
//{
//	while(ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC) == RESET);
//	wyn = ADC_GetConversionValue(ADC1);
//	if(wyn<500){
//		GPIO_SetBits(GPIOD, GPIO_Pin_13);
//	}
//	else {
//		GPIO_ResetBits(GPIOD, GPIO_Pin_13);
//	}
//}
