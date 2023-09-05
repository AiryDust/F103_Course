#include "stm32f10x.h"
#include "bsp_led.h"

int main(void)
{
	LED_GPIO_Init();
	LED_Ctrl(LED_G_GPIO_PIN, ON);
	LED_Ctrl(LED_R_GPIO_PIN, ON);
}

