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
