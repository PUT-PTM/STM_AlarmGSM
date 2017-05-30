#include "init.h"

	void setup()
	{
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_DAC, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
<<<<<<< HEAD
=======

>>>>>>> 7c806cb2996f824becf1c0105395c851b71b2878


	//============ PIN ===============

	GPIO_InitTypeDef  GPIO_InitStructure;

	// PA1 Magnetic Sensor ADC
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AN;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	// PB0 - IR Sensor
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOB, &GPIO_InitStructure);

	// PA4 Alarm
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AN;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	// LEDs
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOD, &GPIO_InitStructure);

	// PA0 Button ON/OFF
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	// PC10 PC11 Rx i Tx (USART) (10=TX,11=RX)
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10 | GPIO_Pin_11;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC, &GPIO_InitStructure);


	//============ TIMER ===============

<<<<<<< HEAD
=======
	//============ TIMER ===============

>>>>>>> 7c806cb2996f824becf1c0105395c851b71b2878
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure; // Audio
	TIM_TimeBaseStructure.TIM_Period = 524;
	TIM_TimeBaseStructure.TIM_Prescaler = 9;
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseStructure.TIM_CounterMode =  TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure);

	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure2; // Alarm
	TIM_TimeBaseStructure2.TIM_Period = 15999;
	TIM_TimeBaseStructure2.TIM_Prescaler = 5999;
	TIM_TimeBaseStructure2.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseStructure2.TIM_CounterMode =  TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure2);

<<<<<<< HEAD

=======
>>>>>>> 7c806cb2996f824becf1c0105395c851b71b2878
	//============ NVIC   ===============

	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1); // Audio
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel = TIM4_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x00;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x00;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
	TIM_ClearITPendingBit(TIM4, TIM_IT_Update);
	TIM_ITConfig(TIM4, TIM_IT_Update, ENABLE);

	NVIC_InitTypeDef NVIC_InitStructure2; // Alarm
	NVIC_InitStructure2.NVIC_IRQChannel = TIM3_IRQn;
	NVIC_InitStructure2.NVIC_IRQChannelPreemptionPriority = 0x01;
	NVIC_InitStructure2.NVIC_IRQChannelSubPriority = 0x01;
	NVIC_InitStructure2.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure2);
	TIM_ClearITPendingBit(TIM3, TIM_IT_Update);
	TIM_ITConfig(TIM3, TIM_IT_Update, ENABLE);


	//============ EXTI ===============
	// Interrupt ON/OFF
<<<<<<< HEAD

=======
>>>>>>> 7c806cb2996f824becf1c0105395c851b71b2878
	NVIC_InitStructure.NVIC_IRQChannel = EXTI0_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x00;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x00;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
	EXTI_InitTypeDef EXTI_InitStructure;
	EXTI_InitStructure.EXTI_Line = EXTI_Line0;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);
	//YSCFG_EXTILineConfig(GPIOB, EXTI_PinSource1);


<<<<<<< HEAD
	//============ ADC ===============
	// Magnetic Sensor
=======
>>>>>>> 7c806cb2996f824becf1c0105395c851b71b2878

	//============ ADC ===============
	// Magnetic Sensor
	ADC_CommonInitTypeDef ADC_CommonInitStructure;
	ADC_CommonInitStructure.ADC_Mode = ADC_Mode_Independent;
	ADC_CommonInitStructure.ADC_Prescaler = ADC_Prescaler_Div2;
	ADC_CommonInitStructure.ADC_DMAAccessMode = ADC_DMAAccessMode_Disabled;
	ADC_CommonInitStructure.ADC_TwoSamplingDelay = ADC_TwoSamplingDelay_5Cycles;
	ADC_CommonInit(&ADC_CommonInitStructure);
	ADC_InitTypeDef ADC_InitStructure;
	ADC_InitStructure.ADC_Resolution = ADC_Resolution_12b;
	ADC_InitStructure.ADC_ScanConvMode = DISABLE;
	ADC_InitStructure.ADC_ContinuousConvMode = ENABLE;
	ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_T1_CC1;
	ADC_InitStructure.ADC_ExternalTrigConvEdge = ADC_ExternalTrigConvEdge_None;
	ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;
	ADC_InitStructure.ADC_NbrOfConversion = 1;
	ADC_Init(ADC1, &ADC_InitStructure);
	ADC_RegularChannelConfig(ADC1, ADC_Channel_1, 1, ADC_SampleTime_84Cycles);
	ADC_Cmd(ADC1, ENABLE);
	ADC_SoftwareStartConv(ADC1);

	//============ DAC ===============
	// Audio
<<<<<<< HEAD

=======
>>>>>>> 7c806cb2996f824becf1c0105395c851b71b2878
	DAC_InitTypeDef DAC_InitStructure;
	DAC_InitStructure.DAC_Trigger = DAC_Trigger_None;
	DAC_InitStructure.DAC_WaveGeneration = DAC_WaveGeneration_None;
	DAC_InitStructure.DAC_LFSRUnmask_TriangleAmplitude = DAC_LFSRUnmask_Bit0;
	DAC_InitStructure.DAC_OutputBuffer = DAC_OutputBuffer_Enable;
	DAC_Init(DAC_Channel_1, &DAC_InitStructure);
	DAC_Cmd(DAC_Channel_1, ENABLE);


	//============ USART ===============
	// GSM
//	// USART3
//	// ustawienie funkcji alternatywnej dla pinów (USART)
//	GPIO_PinAFConfig(GPIOC, GPIO_PinSource10, GPIO_AF_USART3);
//	GPIO_PinAFConfig(GPIOC, GPIO_PinSource11, GPIO_AF_USART3);
//
//	USART_InitTypeDef USART_InitStructure;
//	USART_InitStructure.USART_BaudRate = 115200;
//	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
//	USART_InitStructure.USART_StopBits = USART_StopBits_1;
//	USART_InitStructure.USART_Parity = USART_Parity_No;
//	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
//	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
//	USART_Init(USART3, &USART_InitStructure);
//	USART_Cmd(USART3, ENABLE);

<<<<<<< HEAD

	//============ DELAY ===============

	TM_DELAY_Init();
}


=======
	//============ DELAY ===============
	TM_DELAY_Init();
}


>>>>>>> 7c806cb2996f824becf1c0105395c851b71b2878
void lighton(int number)
	{
		switch(number)
		{
		case 12:
			GPIO_SetBits(GPIOD, GPIO_Pin_12);
			break;
		case 13:
			GPIO_SetBits(GPIOD, GPIO_Pin_13);
			break;
		case 14:
			GPIO_SetBits(GPIOD, GPIO_Pin_14);
			break;
		case 15:
			GPIO_SetBits(GPIOD, GPIO_Pin_15);
			break;
	}
}

void lightoff(int number)
	{
		switch(number)
		{
		case 12:
			GPIO_ResetBits(GPIOD, GPIO_Pin_12);
			break;
		case 13:
			GPIO_ResetBits(GPIOD, GPIO_Pin_13);
			break;
		case 14:
			GPIO_ResetBits(GPIOD, GPIO_Pin_14);
			break;
		case 15:
			GPIO_ResetBits(GPIOD, GPIO_Pin_15);
			break;
	}
}
