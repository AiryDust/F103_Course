// bsp ：board support package 板级支持包
#include "bsp_led.h"

void LED_GPIO_Init(void)
{
	GPIO_InitTypeDef  GPIO_InitStruct;
	
	RCC_APB2PeriphClockCmd(LED_GPIO_CLK, ENABLE);
	GPIO_InitStruct.GPIO_Pin = LED_R_GPIO_PIN | LED_G_GPIO_PIN | LED_B_GPIO_PIN;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(LED_GPIO_PORT, &GPIO_InitStruct);	
	
	GPIO_SetBits(LED_GPIO_PORT, LED_R_GPIO_PIN);
	GPIO_SetBits(LED_GPIO_PORT, LED_G_GPIO_PIN);
	GPIO_SetBits(LED_GPIO_PORT, LED_B_GPIO_PIN);
}

/**
	@parm LED option: [LED_R_GPIO_PIN, LED_G_GPIO_PIN, LED_B_GPIO_PIN]
	@parm state option:[ON, OFF]
*/
void LED_Ctrl(uint16_t LED, BitAction state)
{
	GPIO_WriteBit(LED_GPIO_PORT, LED, state);
}

void LED_TOGGLE(uint16_t LED)
{
	if (GPIO_ReadOutputDataBit(LED_GPIO_PORT, LED))
	{
		GPIO_ResetBits(LED_GPIO_PORT, LED);
	}else{
		GPIO_SetBits(LED_GPIO_PORT, LED);
	}
}

