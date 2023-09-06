#include "bsp_rccclkconfig.h"

void HSE_SetSysClock( uint32_t pllmul )
{
	ErrorStatus HSEStatus;
	//��ʼ��rcc�Ĵ���
	RCC_DeInit();
	
	//ʹ��HSE
	RCC_HSEConfig(RCC_HSE_ON);
	//�ȴ�HSE�ȶ�
	HSEStatus=RCC_WaitForHSEStartUp();
	if(HSEStatus==SUCCESS)
	{
		// �������� Ԥȡָ ��ִ��ÿ�г���֮��ĵȴ�ʱ�� Ƶ��Խ�� ֵԽ��
		//FLASH_Latency_0: FLASH Zero Latency cycle
    //FLASH_Latency_1: FLASH One Latency cycle
    //FLASH_Latency_2: FLASH Two Latency cycles
		FLASH_PrefetchBufferCmd(FLASH_PrefetchBuffer_Enable);
		FLASH_SetLatency(FLASH_Latency_2);
		
		//����AHB,APB1,APB2��Ƶ����
		RCC_HCLKConfig(RCC_SYSCLK_Div1);
    RCC_PCLK1Config(RCC_HCLK_Div2);
    RCC_PCLK2Config(RCC_HCLK_Div1);
		
		//�������໷ʱ����Դ�Լ���Ƶ����
		RCC_PLLConfig(RCC_PLLSource_HSE_Div1, pllmul);
		//ʹ�����໷
		RCC_PLLCmd(ENABLE);
		
		//�ȴ����໷�ȶ�
		while( RCC_GetFlagStatus(RCC_FLAG_PLLRDY) == RESET );
		//�����໷����Ϊϵͳʱ��
		RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);
		while( RCC_GetSYSCLKSource() != 0x08 );
	}
	else 
	{
		//��Ӵ������
	}
}



void HSI_SetSysClk( uint32_t RCC_PLLMul_x )
{
	__IO uint32_t HSIStatus = 0;
	
	// ��RCC �Ĵ�����λ�ɸ�λֵ
	RCC_DeInit();	

	// ʹ�� HSI 
	RCC_HSICmd(ENABLE);
	
	HSIStatus = RCC->CR & RCC_CR_HSIRDY;
	
	if( HSIStatus == RCC_CR_HSIRDY )
	{
		// ʹ��Ԥȡָ
		FLASH_PrefetchBufferCmd(FLASH_PrefetchBuffer_Enable);
		FLASH_SetLatency(FLASH_Latency_2);
		
		RCC_HCLKConfig(RCC_SYSCLK_Div1);
		RCC_PCLK1Config(RCC_HCLK_Div2);
		RCC_PCLK2Config(RCC_HCLK_Div1);
		
		// ���� PLLCLK = HSE * RCC_PLLMul_x
    RCC_PLLConfig(RCC_PLLSource_HSI_Div2, RCC_PLLMul_x);
		
    // ʹ��PLL
		RCC_PLLCmd(ENABLE);
		
		// �ȴ�PLL�ȶ�
		while( RCC_GetFlagStatus(RCC_FLAG_PLLRDY) == RESET );
		
    // ѡ��ϵͳʱ��
		RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);
		
    while( RCC_GetSYSCLKSource() != 0x08 );
	}
	else
  {
		/* ���HSI ����ʧ�ܣ��û�������������Ӵ������Ĵ��� */
	}
}




