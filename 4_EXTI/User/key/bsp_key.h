#ifndef BSP_KEY_H
#define BSP_KEY_H
#include "stm32f10x.h"

#define KEY_1_Pin    GPIO_Pin_0
#define KEY_1_Port   GPIOA
#define KEY_1_Clk    RCC_APB2Periph_GPIOA
#define KEY_2_Pin    GPIO_Pin_13
#define KEY_2_Port   GPIOC
#define KEY_2_Clk    RCC_APB2Periph_GPIOC

void Key_GPIO_Init(void);
uint8_t Get_Key_Statue(uint16_t GPIO_Pin);


#endif //BSP_KEY_H
