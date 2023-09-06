#ifndef _BSP_RCC_H
#define _BSP_RCC_H

#include "stm32f10x.h"

/**
@param  RCC_PLLMul: specifies the PLL multiplication factor.
				this parameter can be RCC_PLLMul_x where x:[2,16]  
*/
void HSE_SetSysClk(uint32_t RCC_PLLMul_x);
#endif
