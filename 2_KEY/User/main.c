#include "stm32f10x.h"
#include "bsp_led.h"
#include "bsp_key.h"

int main(void)
{
	int i = 0;
	LED_GPIO_Init();
	Key_GPIO_Init();
	
	while(1)
	{
		if (Get_Key_Statue(KEY_1_Pin)){
			LED_Ctrl(LED_R_GPIO_PIN, ON);
		}else{
			LED_Ctrl(LED_R_GPIO_PIN, OFF);
		}
	}
	
	
	return 0;
}
