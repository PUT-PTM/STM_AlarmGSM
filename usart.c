#include "usart.h"

char c;
void send_char(char c)
{
    while (USART_GetFlagStatus(USART3, USART_FLAG_TXE) == RESET);
    USART_SendData(USART3, c);
}
void send_string(const char* s)
{
    while (*s)
        send_char(*s++);
}

void USART3_IRQHandler(void)
{
	// sprawdzenie flagi zwiazanej z odebraniem danych przez USART
	if(USART_GetITStatus(USART3, USART_IT_RXNE) != RESET)
	{
		int i=0;
		c = USART_ReceiveData(USART3);
		if(c=='\r'){
			 send_string("AT+CMGS=30");
			 for(i=0;i<80000000;i++);
			 send_string("001100098188786566F60000aa13F43C685D97DFDFA0B09B9E87BFD9F37518");
		}
		// odebrany bajt znajduje sie w rejestrze USART3->DR
	}
}

//uint8_t usartGetChar(void)
//{
//	// czekaj na odebranie danych
//       while (USART_GetFlagStatus(USART3, USART_FLAG_RXNE) == RESET);
//       	char c = USART_ReceiveData(USART3);
//        send_char(c);
//   	return c;
//}
//int i=0;
//		if(flaga==1){
//			//for(i=0;i<160000000;i++);
//		}
//
//		if(flaga==1){
//			send_string("AT");
//			flaga=0;
//		}
//		char c;
//		if(usartGetChar()=='r')
//			{
//				GPIO_SetBits(GPIOD, GPIO_Pin_12 | GPIO_Pin_13);
//					 send_string("AT+CMGS=30");
//					 for(i=0;i<80000000;i++);
//					 send_string("001100098188786566F60000aa13F43C685D97DFDFA0B09B9E87BFD9F37518");
//				}
//				// odebrany bajt znajduje sie w rejestrze USART3->DR
//			}




int usartTest(void)
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
