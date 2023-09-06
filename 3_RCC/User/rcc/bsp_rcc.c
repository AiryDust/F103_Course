#include "bsp_rcc.h"

void HSE_SetSysClk( uint32_t RCC_PLLMul_x )
{

	// ��������RCCʱ��
	RCC_DeInit();	

	//  ���ⲿʱ��
	RCC_HSEConfig(RCC_HSE_ON);
	
	if(RCC_WaitForHSEStartUp())
	{
		// ʹ��Ԥȡַ
		FLASH_PrefetchBufferCmd(FLASH_PrefetchBuffer_Enable);
		FLASH_SetLatency(FLASH_Latency_2);
		
		
		RCC_HCLKConfig(RCC_SYSCLK_Div1); //AHBһ��Ƶ
		RCC_PCLK1Config(RCC_HCLK_Div2); //APB1����Ƶ
		RCC_PCLK2Config(RCC_HCLK_Div1); //APB2һ��Ƶ
		
		// PLLMUL���໷�ź���Դ����Ƶ����ѡ��
    RCC_PLLConfig(RCC_PLLSource_HSE_Div1, RCC_PLLMul_x);
		
    // ʹ��PLL���໷
		RCC_PLLCmd(ENABLE);
		
		// 
		while( RCC_GetFlagStatus(RCC_FLAG_PLLRDY) == RESET );
		
    // ����SWϵͳʱ����Դ
		RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);
		
    while( RCC_GetSYSCLKSource() != 0x08 );
	}
	else
  {
		/*  */
	}
}
