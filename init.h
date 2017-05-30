#include "stm32f4xx_gpio.h"
#include "stm32f4xx_usart.h"
#include "stm32f4xx_tim.h"
#include "stm32f4xx_adc.h"
#include "stm32f4xx_dac.h"
#include "stm32f4xx_exti.h"
#include "misc.h"
#include "tm_stm32f4_delay.h" // Library 03- STM32F4 by Tilen Majerle http://stm32f4-discovery.net
#include <stdbool.h>

void setup(); // Initialization
void lighton(int number);
void lightoff(int number);


