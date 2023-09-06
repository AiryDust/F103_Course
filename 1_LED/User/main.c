#include "stm32f10x.h"
#include "bsp_led.h"

int main(void)
{
	int i;
	LED_GPIO_Init();
	
	while(1){
		LED_TOGGLE(LED_G_GPIO_PIN);
		for (i=0;i<0xfffff;i++);
		LED_TOGGLE(LED_G_GPIO_PIN);
		for (i=0;i<0xfffff;i++);
	}
}

