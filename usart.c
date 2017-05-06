#include "usart.h"




uint8_t usartGetChar(void)
{
	// czekaj na odebranie danych
       while (USART_GetFlagStatus(USART3, USART_FLAG_RXNE) == RESET);


   	return USART_ReceiveData(USART3);
}



void USART3_IRQHandler(void)
{
	// sprawdzenie flagi zwiazanej z odebraniem danych przez USART
	if(USART_GetITStatus(USART3, USART_IT_RXNE) != RESET)
{
		// odebrany bajt znajduje sie w rejestrze USART3->DR
	}
}






int usart1(void)
{

//przerwania,narazie nie ruszam

//	//struktura do konfiguracji kontrolera NVIC
//	NVIC_InitTypeDef NVIC_InitStructure;
//	// wlaczenie przerwania zwi¹zanego z odebraniem danych (pozostale zrodla przerwan zdefiniowane sa w pliku stm32f4xx_usart.h)
//	USART_ITConfig(USART3, USART_IT_RXNE, ENABLE);
//	NVIC_InitStructure.NVIC_IRQChannel = USART3_IRQn;
//	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
//	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
//	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
//	// konfiguracja kontrolera przerwan
//	NVIC_Init(&NVIC_InitStructure);
//	// wlaczenie przerwan od ukladu USART
//	NVIC_EnableIRQ(USART3_IRQn);



    			//czekaj na opró¿nienie bufora wyjœciowego
    	    	while(USART_GetFlagStatus(USART3, USART_FLAG_TXE) == RESET);
    	    	// wyslanie danych
    	    	USART_SendData(USART3, 'A');
    	    	// czekaj az dane zostana wyslane
    	    	while (USART_GetFlagStatus(USART3, USART_FLAG_TC) == RESET);
}
