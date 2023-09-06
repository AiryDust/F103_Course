#include "stm32f10x.h"   // 相当于51单片机中的  #include <reg51.h>
#include "bsp_led.h"
#include "bsp_exti.h"
int main(void)
{
	LED_GPIO_Init();
	EXIT_Key_Config();
	// 来到这里的时候，系统的时钟已经被配置成72M。
	while(1);
}
