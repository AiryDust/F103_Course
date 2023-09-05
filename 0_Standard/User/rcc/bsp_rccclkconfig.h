#ifndef __BSP_RCCCLKCONFIG_H
#define __BSP_RCCCLKCONFIG_H

#include "stm32f10x.h"

void HSE_SetSysClock( uint32_t pllmul );   //pllmul = RCC_PLLMul_x £¨2<=x<=16£©
void HSI_SetSysClk( uint32_t RCC_PLLMul_x );



#endif    //__BSP_RCCCLKCONFIG_H




