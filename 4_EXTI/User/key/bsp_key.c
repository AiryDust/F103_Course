#include "bsp_key.h"
void Key_GPIO_Init(void)
{
	GPIO_InitTypeDef KEY_GPIO_InitStruct;
	
	//打开时钟
	RCC_APB2PeriphClockCmd(KEY_1_Clk, ENABLE);
	RCC_APB2PeriphClockCmd(KEY_2_Clk, ENABLE);
	//初始化两个端口
	KEY_GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPU;
	KEY_GPIO_InitStruct.GPIO_Pin = KEY_1_Pin;
	KEY_GPIO_InitStruct.GPIO_Speed= GPIO_Speed_50MHz;
	GPIO_Init(KEY_1_Port, &KEY_GPIO_InitStruct);
	
	KEY_GPIO_InitStruct.GPIO_Pin = KEY_2_Pin;
	GPIO_Init(KEY_2_Port, &KEY_GPIO_InitStruct);
}

uint8_t Get_Key_Statue(uint16_t GPIO_Pin)
{
	GPIO_TypeDef* GPIO_Port;
	if (GPIO_Pin==KEY_1_Pin){ GPIO_Port = KEY_1_Port;}else{GPIO_Port = KEY_2_Port;}
	return GPIO_ReadInputDataBit(GPIO_Port, GPIO_Pin);
}
