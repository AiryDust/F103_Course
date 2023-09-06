#include "bsp_rccclkconfig.h"

void HSE_SetSysClock( uint32_t pllmul )
{
	ErrorStatus HSEStatus;
	//初始化rcc寄存器
	RCC_DeInit();
	
	//使能HSE
	RCC_HSEConfig(RCC_HSE_ON);
	//等待HSE稳定
	HSEStatus=RCC_WaitForHSEStartUp();
	if(HSEStatus==SUCCESS)
	{
		// 操作闪存 预取指 即执行每行程序之间的等待时间 频率越大 值越大
		//FLASH_Latency_0: FLASH Zero Latency cycle
    //FLASH_Latency_1: FLASH One Latency cycle
    //FLASH_Latency_2: FLASH Two Latency cycles
		FLASH_PrefetchBufferCmd(FLASH_PrefetchBuffer_Enable);
		FLASH_SetLatency(FLASH_Latency_2);
		
		//配置AHB,APB1,APB2分频因子
		RCC_HCLKConfig(RCC_SYSCLK_Div1);
    RCC_PCLK1Config(RCC_HCLK_Div2);
    RCC_PCLK2Config(RCC_HCLK_Div1);
		
		//配置锁相环时钟来源以及倍频因子
		RCC_PLLConfig(RCC_PLLSource_HSE_Div1, pllmul);
		//使能锁相环
		RCC_PLLCmd(ENABLE);
		
		//等待锁相环稳定
		while( RCC_GetFlagStatus(RCC_FLAG_PLLRDY) == RESET );
		//将锁相环设置为系统时钟
		RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);
		while( RCC_GetSYSCLKSource() != 0x08 );
	}
	else 
	{
		//添加错误代码
	}
}



void HSI_SetSysClk( uint32_t RCC_PLLMul_x )
{
	__IO uint32_t HSIStatus = 0;
	
	// 把RCC 寄存器复位成复位值
	RCC_DeInit();	

	// 使能 HSI 
	RCC_HSICmd(ENABLE);
	
	HSIStatus = RCC->CR & RCC_CR_HSIRDY;
	
	if( HSIStatus == RCC_CR_HSIRDY )
	{
		// 使能预取指
		FLASH_PrefetchBufferCmd(FLASH_PrefetchBuffer_Enable);
		FLASH_SetLatency(FLASH_Latency_2);
		
		RCC_HCLKConfig(RCC_SYSCLK_Div1);
		RCC_PCLK1Config(RCC_HCLK_Div2);
		RCC_PCLK2Config(RCC_HCLK_Div1);
		
		// 配置 PLLCLK = HSE * RCC_PLLMul_x
    RCC_PLLConfig(RCC_PLLSource_HSI_Div2, RCC_PLLMul_x);
		
    // 使能PLL
		RCC_PLLCmd(ENABLE);
		
		// 等待PLL稳定
		while( RCC_GetFlagStatus(RCC_FLAG_PLLRDY) == RESET );
		
    // 选择系统时钟
		RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);
		
    while( RCC_GetSYSCLKSource() != 0x08 );
	}
	else
  {
		/* 如果HSI 启动失败，用户可以在这里添加处理错误的代码 */
	}
}




