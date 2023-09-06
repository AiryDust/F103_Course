#ifndef __BSP_LED_H
#define __BSP_LED_H

#include "stm32f10x.h"

#define LED_GPIO_PORT               GPIOB
#define LED_GPIO_CLK                RCC_APB2Periph_GPIOB
#define LED_R_GPIO_PIN              GPIO_Pin_5
#define LED_G_GPIO_PIN              GPIO_Pin_0
#define LED_B_GPIO_PIN              GPIO_Pin_1
#define ON                          Bit_RESET
#define OFF                         Bit_SET

void LED_GPIO_Init(void);
void LED_Ctrl(uint16_t, BitAction);
void LED_TOGGLE(uint16_t LED);


#endif /* __BSP_LED_H */

