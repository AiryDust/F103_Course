#include "stm32f10x.h"   // �൱��51��Ƭ���е�  #include <reg51.h>
#include "bsp_led.h"
#include "bsp_exti.h"
int main(void)
{
	LED_GPIO_Init();
	EXIT_Key_Config();
	// ���������ʱ��ϵͳ��ʱ���Ѿ������ó�72M��
	while(1);
}
