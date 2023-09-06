#include "stm32f10x.h"
#include "bsp_led.h"
#include "bsp_rcc.h"
int main(void)
{
	int i;
	HSE_SetSysClk(RCC_PLLMul_9);
	LED_GPIO_Init();
	while(1)
	{
		LED_Ctrl(LED_G_GPIO_PIN, ON);
		for(i=0;i<0xfffff;i++);
		LED_Ctrl(LED_G_GPIO_PIN, OFF);
		for(i=0;i<0xfffff;i++);
	}
	
}

