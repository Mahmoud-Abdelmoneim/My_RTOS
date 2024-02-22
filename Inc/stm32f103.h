/*************************************************************************/
/****     file      : stm32f103.h                                     ****/
/****     Target    : STM32F103C8T6                                   ****/
/****     Author    : Mahmoud Abdelmoniem                             ****/
/****     Date      : 1/2024                                          ****/
/****     version    : 0.0                                            ****/
/*************************************************************************/
#ifndef STM32F103_H
#define STM32F103_H
#include <stdint.h>

/***********************   Variuos Memory Base Adresses   ***************************/
#define FLASH_BASE_ADDRESS          0X08000000UL
#define SRAM_BASE_ADDRESS           0X20000000UL


/***********************   Core Peripherals Base Adresses   ***************************/
#define SYSTICK_BASE_ADDRES         0xE000E010UL
/***********************   AHB Peripherals Base Adresses   ***************************/

#define RCC_BASE_ADRESS                   0x40021000U

#define DMA_BASE_ADRESS                   0x40020000U
#define DMA_INTERRUPT_REG_BASE_ADDRESS    DMA_BASE_ADRESS

#define 		SCB_BASE_ADDRESS 			   	   (0xE000ED00)
/***********************   APB1 Peripherals Base Adresses   ***************************/

#define USART2_BASE_ADDRESS     0x40004800UL
#define USART3_BASE_ADDRESS     0x40013800UL

/***********************   APB2 Peripherals Base Adresses   ***************************/
#define GPIOA_BASE_ADDRESS           0x40010800U
#define GPIOB_BASE_ADDRESS           0x40010C00U
#define GPIOC_BASE_ADDRESS           0x40011000U
#define GPIOD_BASE_ADDRESS           0x40011400U
#define GPIOE_BASE_ADDRESS           0x40011800U


#define EXTI_BASE_ADDRESS           0x40010400U

#define AFIO_BASE_ADDRESS			0x40010000U


#define PERIPH_BASE           0x40000000UL
#define AHBPERIPH_BASE       (PERIPH_BASE + 0x00020000UL)
#define DMA_Channel1_BASE    (AHBPERIPH_BASE + 0x00000008UL)
#define DMA_Channel2_BASE    (AHBPERIPH_BASE + 0x0000001CUL)
#define DMA_Channel3_BASE    (AHBPERIPH_BASE + 0x00000030UL)
#define DMA_Channel4_BASE    (AHBPERIPH_BASE + 0x00000044UL)
#define DMA_Channel5_BASE    (AHBPERIPH_BASE + 0x00000058UL)
#define DMA_Channel6_BASE    (AHBPERIPH_BASE + 0x0000006CUL)
#define DMA_Channel7_BASE    (AHBPERIPH_BASE + 0x00000080UL)



#define USART1_BASE_ADDRESS     0x40013800UL

/***********************   core peripherals Register Defention Structure   ***************************/

typedef struct{

	volatile uint32_t CSR;      /*SysTick TIM control status register*/
	volatile uint32_t RVR;      /*SysTick TIM Reload Value Register*/
	volatile uint32_t CVR;      /*SysTick TIM Current value register */
	volatile uint32_t CALIB;    /*SysTick TIM Calibration value Register*/
}SysTick_RegDef_t;

/***********************   RCC Register Defention Structure   ***************************/
typedef struct{

	volatile uint32_t CR;             /*RCC Clock Control Register */
	volatile uint32_t CFGR;           /*RCC Clock Configuration Register*/
	volatile uint32_t CIR;            /*RCC Clock interrupt register*/
	volatile uint32_t APB2RSTR;       /*RCC APB Peripheral Rest register*/
	volatile uint32_t APB1RSTR;       /*RCC APB Peripheral Rest register*/
	volatile uint32_t AHBENR;         /*RCC AAHB peripehral Clock enable Register */
	volatile uint32_t APB2ENR;        /*RCC APP2 peripheral Clock enable Register */
	volatile uint32_t APB1ENR;        /*RCC APP1 peripheral Clock enable Register */
	volatile uint32_t BDCR;           /*RCC Backup control domain Register*/
	volatile uint32_t CSR;            /*RCC Control status register*/

}RCC_RegDef_t;
/***********************   DMA Register Defention Structure   ***************************/
typedef struct{
	volatile uint32_t CCR;    /*DMA Channel x configuration Register*/
	volatile uint32_t CNDTR;  /*DMA Channel x Number of data register Register*/
	volatile uint32_t CPAR;   /*DMA Channel x peripheral address Register*/
	volatile uint32_t CMAR;   /*DMA Channel x memory address Register*/
}DMA_RegChannelDef_t;

typedef struct{
	volatile uint32_t ISR;
	volatile uint32_t IFCR;
}DMA_RefInterruptDef_t;

/***********************   GPIO Register Defention Structure   ***************************/


typedef struct{

volatile uint32_t CRL;               /*GPIO PORT Configuration register low */ 
volatile uint32_t CRH;               /*GPIO PORT Configuration register low   */ 
volatile uint32_t IDR;               /*GPIO PORT Input Data Register   */ 
volatile uint32_t ODR;               /*GPIO PORT Output Data Register   */ 
volatile uint32_t BSRR;              /*GPIO PORT Bit Set/Rest Register   */ 
volatile uint32_t BRR;               /*GPIO PORT Bit Rest Register   */ 
volatile uint32_t LCKR;              /*GPIO PORT Configuration Lock register   */ 
}GPIO_RegDef_t;



/***********************   EXTI Register Defention Structure   ***************************/


typedef struct{

	volatile uint32_t IMR;   /*EXTI Interrupt Mask Register*/
	volatile uint32_t EMR;   /*EXTI Event Mask Register*/
	volatile uint32_t RTSR;  /*EXTI Rising Trigger Selection Register*/
	volatile uint32_t FTSR;  /*EXTI Falling Trigger Selection Register*/
	volatile uint32_t SWIER; /*EXTI Software Interrupt Event Register */
	volatile uint32_t PR;    /*EXTI Pending Register*/
}EXTI_RegDef_t;

/***********************   AFIO Register Defention Structure   ***************************/
typedef struct{

	volatile uint32_t EVCR;     /*AFIO Event Control Register*/
	volatile uint32_t MAPR;     /*AFIO remap and debug information  Register*/
	volatile uint32_t EXTICR[3];  /*AFIO external interrupt configuration Register*/
}AFIO_RegDef_t;



/***********************   USART Register Defention Structure   ***************************/


typedef struct{
    volatile uint32_t SR ;          /*USART status Register*/
    volatile uint32_t DR;           /*USART data Register*/
	volatile uint32_t BRR;          /*USART baud rate Register*/
	volatile uint32_t CR1;          /*USART control 1Register*/
	volatile uint32_t CR2;          /*USART control 2Register*/
	volatile uint32_t CR3;          /*USART control 3Register*/
	volatile uint32_t GTPR;         /*USART Guard time prescaler Register*/
}USART_RegDef_t;



/***********************   SCB Register Defention Structure   ***************************/

typedef struct
{
  volatile uint32_t CPUID;                  /*!< Offset: 0x000 (R/ )  CPUID Base Register */
  volatile uint32_t ICSR;                   /*!< Offset: 0x004 (R/W)  Interrupt Control and State Register */
  volatile uint32_t VTOR;                   /*!< Offset: 0x008 (R/W)  Vector Table Offset Register */
  volatile uint32_t AIRCR;                  /*!< Offset: 0x00C (R/W)  Application Interrupt and Reset Control Register */
  volatile uint32_t SCR;                    /*!< Offset: 0x010 (R/W)  System Control Register */
  volatile uint32_t CCR;                    /*!< Offset: 0x014 (R/W)  Configuration Control Register */
  volatile uint32_t SHP[12U];               /*!< Offset: 0x018 (R/W)  System Handlers Priority Registers (4-7, 8-11, 12-15) */
  volatile uint32_t SHCSR;                  /*!< Offset: 0x024 (R/W)  System Handler Control and State Register */
  volatile uint32_t CFSR;                   /*!< Offset: 0x028 (R/W)  Configurable Fault Status Register */
  volatile uint32_t HFSR;                   /*!< Offset: 0x02C (R/W)  HardFault Status Register */
  volatile uint32_t DFSR;                   /*!< Offset: 0x030 (R/W)  Debug Fault Status Register */
  volatile uint32_t MMFAR;                  /*!< Offset: 0x034 (R/W)  MemManage Fault Address Register */
  volatile uint32_t BFAR;                   /*!< Offset: 0x038 (R/W)  BusFault Address Register */
  volatile uint32_t AFSR;                   /*!< Offset: 0x03C (R/W)  Auxiliary Fault Status Register */
  volatile uint32_t PFR[2U];                /*!< Offset: 0x040 (R/ )  Processor Feature Register */
  volatile uint32_t DFR;                    /*!< Offset: 0x048 (R/ )  Debug Feature Register */
  volatile uint32_t ADR;                    /*!< Offset: 0x04C (R/ )  Auxiliary Feature Register */
  volatile uint32_t MMFR[4U];               /*!< Offset: 0x050 (R/ )  Memory Model Feature Register */
  volatile uint32_t ISAR[5U];               /*!< Offset: 0x060 (R/ )  Instruction Set Attributes Register */
  volatile uint32_t RESERVED0[5U];
  volatile uint32_t CPACR;                  /*!< Offset: 0x088 (R/W)  Coprocessor Access Control Register */
} SCB_RegDef_t;
/***********************   GPIO peripheral Defention    ***************************/


#define GPIOA                      ((GPIO_RegDef_t*)GPIOA_BASE_ADDRESS)
#define GPIOB                      ((GPIO_RegDef_t*)GPIOB_BASE_ADDRESS)
#define GPIOC                      ((GPIO_RegDef_t*)GPIOC_BASE_ADDRESS)
#define GPIOD                      ((GPIO_RegDef_t*)GPIOD_BASE_ADDRESS)
#define GPIOE                      ((GPIO_RegDef_t*)GPIOE_BASE_ADDRESS)

/***********************   RCC peripheral Defention    ***************************/
#define RCC                        ((RCC_RegDef_t*)RCC_BASE_ADRESS)
/***********************   Core peripheral Defention    ***************************/
#define SYSTICK                     ((SysTick_RegDef_t*)SYSTICK_BASE_ADDRES)
/***********************   EXTI peripheral Defention    ***************************/
#define EXTI                       ((EXTI_RegDef_t*)EXTI_BASE_ADDRESS)
/***********************   AFIO peripheral Defention    ***************************/
#define AFIO                       ((AFIO_RegDef_t*)AFIO_BASE_ADDRESS)
/***********************   DMA peripheral Defention    ***************************/
#define DMA_INT                       ((DMA_RefInterruptDef_t*)DMA_INTERRUPT_REG_BASE_ADDRESS)
#define DMA_Channel1                   ((DMA_RegChannelDef_t *)DMA_Channel1_BASE)
#define DMA_Channel2                   ((DMA_RegChannelDef_t *)DMA_Channel2_BASE)
#define DMA_Channel3                   ((DMA_RegChannelDef_t *)DMA_Channel3_BASE)
#define DMA_Channel4                   ((DMA_RegChannelDef_t *)DMA_Channel4_BASE)
#define DMA_Channel5                   ((DMA_RegChannelDef_t *)DMA_Channel5_BASE)
#define DMA_Channel6                   ((DMA_RegChannelDef_t *)DMA_Channel6_BASE)
#define DMA_Channel7                   ((DMA_RegChannelDef_t *)DMA_Channel7_BASE)
/***********************   usart peripheral Defention    ***************************/
#define USART1                   ((USART_RegDef_t *)USART1_BASE_ADDRESS)
#define USART2                   ((USART_RegDef_t *)USART2_BASE_ADDRESS)
#define USART3                   ((USART_RegDef_t *)USART3_BASE_ADDRESS)

/***********************   usart peripheral Defention    ***************************/
#define SCB                   ((SCB_RegDef_t *)SCB_BASE_ADDRESS)
#endif
