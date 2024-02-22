/*************************************************************************/
/****     Target    : RCC_prog.c                                      ****/
/****     Target    : STM32F103C8T6                                   ****/
/****     Author    : Mahmoud Abdelmoniem                             ****/
/****     Date      : 1/2024                                          ****/
/****     version    : 0.0                                            ****/
/*************************************************************************/

#include "RCC_intreface.h"

void RCC_SetClkStatus(Clock_t ClkType,Status_t StatusType)
{

	switch(ClkType)
	{
	case HSE_CLK:
		if(StatusType == CLK_ON)
		{
			SET_BIT(RCC->CR,16);
			while(!READ_BIT(RCC->CR,17));

		}
		else{
			CLEAR_BIT(RCC->CR,16);
		}
		break;
	case HSI_CLK:
		if(StatusType == CLK_ON)
		{
			SET_BIT(RCC->CR,0);
			while(!READ_BIT(RCC->CR,1));
		}
		else{
			CLEAR_BIT(RCC->CR,0);
		}
		break;
	case PLL_CLK:
		if(StatusType == CLK_ON)
		{
			SET_BIT(RCC->CR,24);
			while(!READ_BIT(RCC->CR,24));
		}
		else{
			CLEAR_BIT(RCC->CR,24);
		}
		break;
	}
}
void RCC_SetSystemClk(Clock_t ClkType)
{
	RCC->CFGR |= ClkType;
}
void RCC_HSE_Config(uint8_t DivFactor)
{
	RCC->CFGR &= ~(DivFactor<<17);
	RCC->CFGR |=  (DivFactor<<17);
}
void RCC_PLL_Config(uint8_t MulFactor,PLLClock_t PLLClockType)
{

}
void RCC_AHB_PeriphralEnableClk(RCC_Peripheral_t periphral)
{
	RCC->AHBENR |=(1<<periphral);
}
void RCC_AHB_PeriphralDisableClk(RCC_Peripheral_t periphral)
{

}
void RCC_APB1_PeriphralEnableClk(RCC_Peripheral_t periphral)
{
	RCC->APB1ENR |= (1<<periphral);
}
void RCC_APB1_PeriphralDisableClk(RCC_Peripheral_t periphral)
{

}
void RCC_APB2_PeriphralEnableClk(RCC_Peripheral_t periphral)
{
	RCC->APB2ENR |= (1<<periphral);
}
void RCC_APB2_PeriphralDisableClk(RCC_Peripheral_t periphral)
{

}

