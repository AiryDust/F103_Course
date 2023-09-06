#include "bsp_rcc.h"

void HSE_SetSysClk( uint32_t RCC_PLLMul_x )
{

	// 重置所有RCC时钟
	RCC_DeInit();	

	//  打开外部时钟
	RCC_HSEConfig(RCC_HSE_ON);
	
	if(RCC_WaitForHSEStartUp())
	{
		// 使能预取址
		FLASH_PrefetchBufferCmd(FLASH_PrefetchBuffer_Enable);
		FLASH_SetLatency(FLASH_Latency_2);
		
		
		RCC_HCLKConfig(RCC_SYSCLK_Div1); //AHB一分频
		RCC_PCLK1Config(RCC_HCLK_Div2); //APB1二分频
		RCC_PCLK2Config(RCC_HCLK_Div1); //APB2一分频
		
		// PLLMUL锁相环信号来源及倍频因子选择
    RCC_PLLConfig(RCC_PLLSource_HSE_Div1, RCC_PLLMul_x);
		
    // 使能PLL锁相环
		RCC_PLLCmd(ENABLE);
		
		// 
		while( RCC_GetFlagStatus(RCC_FLAG_PLLRDY) == RESET );
		
    // 配置SW系统时钟来源
		RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);
		
    while( RCC_GetSYSCLKSource() != 0x08 );
	}
	else
  {
		/*  */
	}
}
