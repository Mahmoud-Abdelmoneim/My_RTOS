/*************************************************************************/
/****     file      : RCC_interace.h                                  ****/
/****     Target    : STM32F103C8T6                                   ****/
/****     Author    : Mahmoud Abdelmoniem                             ****/
/****     Date      : 1/2024                                          ****/
/****     version    : 0.0                                            ****/
/*************************************************************************/
#ifndef RCC_INTREFACE_H_
#define RCC_INTREFACE_H_

#include "Bit_math.h"
#include <stdint.h>
#include "stm32f103.h"

/***   HSE DIV factor  ***/
#define HSE_DIV_BY_1       0X00
#define HSE_DIV_BY_2       0X01


/***   PLL MUL factor  ***/
#define 		PLL_x2_INPUT_CLOCK            	(0x0)
#define 		PLL_x3_INPUT_CLOCK            	(0x1)
#define 		PLL_x4_INPUT_CLOCK            	(0x2)
#define 		PLL_x5_INPUT_CLOCK            	(0x3)
#define 		PLL_x6_INPUT_CLOCK            	(0x4)
#define 		PLL_x7_INPUT_CLOCK            	(0x5)
#define 		PLL_x8_INPUT_CLOCK           	(0x6)
#define 		PLL_x9_INPUT_CLOCK            	(0x7)
#define 		PLL_x10_INPUT_CLOCK             (0x8)
#define 		PLL_x11_INPUT_CLOCK             (0x9)
#define 		PLL_x12_INPUT_CLOCK             (0xA)
#define 		PLL_x13_INPUT_CLOCK             (0xB)
#define 		PLL_x14_INPUT_CLOCK             (0xC)
#define 		PLL_x15_INPUT_CLOCK             (0xD)
#define 		PLL_x16_INPUT_CLOCK             (0xE)
#define 		PLL_x16_2ND_INPUT_CLOCK         (0xF)


/*system clock type*/
typedef enum{
	HSI_CLK,
	HSE_CLK,
	PLL_CLK
}Clock_t;

/*clock status*/
typedef enum {
	CLK_OFF,
	CLK_ON
}Status_t;

/**PLL clock source enum*/
typedef enum{
	HSE_CLK_SRC,
	HSI_CLK_SRC,
	PLLCLK_SRC
}PLLClock_t;



/* Microcontroler  peripherals */
typedef enum
{
	/* RCC AHB PERIPHERALS */
	RCC_DMA1_CLOCK,
	RCC_DMA2_CLOCK,
	RCC_SRAM_CLOCK,
	RCC_FLITF_CLOCK = 4,
	RCC_CRCE_CLOCK  = 6,
	RCC_FSMC_CLOCK  = 8,
	RCC_SDIO_CLOCK  = 10,

	/* RCC APB1ENR PERIPHERALS */
	RCC_TIM2_CLOCK = 0,
	RCC_TIM3_CLOCK,
	RCC_TIM4_CLOCK,
	RCC_TIM5_CLOCK,
	RCC_TIM6_CLOCK,
	RCC_TIM7_CLOCK,
	RCC_TIM12_CLOCK,
	RCC_TIM13_CLOCK,
	RCC_TIM14_CLOCK,
	RCC_WWDGCLOCK = 11,
	RCC_SPI2CLOCK = 14,
	RCC_SPI3CLOCK,
	RCC_USART2_CLOCK = 17,
	RCC_USART3_CLOCK,
	RCC_USART4_CLOCK,
	RCC_USART5_CLOCK,
	RCC_I2C1_CLOCK,
	RCC_I2C2_CLOCK,
	RCC_USB_CLOCK,
	RCC_CAN_CLOCK =25,
	RCC_BKP_CLOCK =27,
	RCC_PWR_CLOCK,
	RCC_DAC_CLOCK,

	/* RCC APB2ENR PERIPHERALS */
	RCC_AFIO_CLOCK  = 0,
	RCC_GPIOA_CLOCK = 2,
	RCC_GPIOB_CLOCK,
	RCC_GPIOC_CLOCK,
	RCC_GPIOD_CLOCK,
	RCC_GPIOE_CLOCK,
	RCC_GPIOF_CLOCK,
	RCC_GPIOG_CLOCK,
	RCC_ADC1_CLOCK = 9,
	RCC_ADC2_CLOCK,
	RCC_TIM1_CLOCK,
	RCC_SPI1_CLOCK,
	RCC_TIM8_CLOCK,
	RCC_USART1_CLOCK,
	RCC_ADC3_CLOCK,
	RCC_TIM9_CLOCK = 19,
	RCC_TIM10_CLOCK,
	RCC_TIM11_CLOCK,
}RCC_Peripheral_t;


/*
 * @breif : this function set the clock status
 * @para  :ClkType-->Clock_t Enum
 * 		   StatusType-->Status_t Enum
 * @return:void
 */
void RCC_SetClkStatus(Clock_t ClkType,Status_t StatusType);
void RCC_SetSystemClk(Clock_t ClkType);
void RCC_HSE_Config(uint8_t DivFactor);
void RCC_PLL_Config(uint8_t MulFactor,PLLClock_t PLLClockType);
void RCC_AHB_PeriphralEnableClk(RCC_Peripheral_t periphral);
void RCC_AHB_PeriphralDisableClk(RCC_Peripheral_t periphral);
void RCC_APB1_PeriphralEnableClk(RCC_Peripheral_t periphral);
void RCC_APB1_PeriphralDisableClk(RCC_Peripheral_t periphral);
void RCC_APB2_PeriphralEnableClk(RCC_Peripheral_t periphral);
void RCC_APB2_PeriphralDisableClk(RCC_Peripheral_t periphral);

#endif /* RCC_INTREFACE_H_ */
