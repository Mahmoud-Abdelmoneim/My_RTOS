#include "OSMCAL_interface.h"
#include <stdint.h>
#include "main.h"
#include "RCC_intreface.h"
#include "GPIO_interface.h"


#define DELAY_1MS                   562
#define DELAY_1S                 (DELAY_1MS *1000)
#define DELAY_500MS              (DELAY_1MS *500)
#define DELAY_250MS              (DELAY_1MS *250)
#define DELAY_125MS              (DELAY_1MS *125)
void delay(uint32_t count)
{
	for(uint32_t i=0;i<count;i++);
}
PinConfig_t pin1={
		.Port=GPIO_PORTA,
		.PinNum=GPIO_PIN_1,
		.Mode=GPIO_OUTPU,
		.OutMaxSpeed =OUTPUT_MAX_SPEED_10_MHz,
		.Outmode=GP_PUSH_PULL
};

PinConfig_t pin2={
		.Port=GPIO_PORTA,
		.PinNum=GPIO_PIN_2,
		.Mode=GPIO_OUTPU,
		.OutMaxSpeed =OUTPUT_MAX_SPEED_10_MHz,
		.Outmode=GP_PUSH_PULL
};
PinConfig_t pin3={
		.Port=GPIO_PORTA,
		.PinNum=GPIO_PIN_3,
		.Mode=GPIO_OUTPU,
		.OutMaxSpeed =OUTPUT_MAX_SPEED_10_MHz,
		.Outmode=GP_PUSH_PULL
};
PinConfig_t pin4={
		.Port=GPIO_PORTA,
		.PinNum=GPIO_PIN_4,
		.Mode=GPIO_OUTPU,
		.OutMaxSpeed =OUTPUT_MAX_SPEED_10_MHz,
		.Outmode=GP_PUSH_PULL
};
int main(void)
{
	RCC_SetSystemClk(HSI_CLK);
	RCC_APB2_PeriphralEnableClk(RCC_GPIOA_CLOCK);
	GPIO_u8PinInit(&pin1);
	GPIO_u8PinInit(&pin2);
	GPIO_u8PinInit(&pin3);
	GPIO_u8PinInit(&pin4);
	EnableSysFualts();
	STk_voidInit(1000);
	Stack_voidSchedulerStackInit(SCHEDULER_STACK_START);
	Stack_voidTaskStackInit();
	ChangeToPSP();
	Task1_Handelr();
    /* Loop forever */
	for(;;);
}

void Task1_Handelr(void)
{
	while(1)
	{
		GPIO_u8TogglePinValue(GPIO_PORTA, GPIO_PIN_1);
		TaskDelay(1000);
	}
}
void Task2_Handelr(void)
{
	while(1)
	{
		GPIO_u8TogglePinValue(GPIO_PORTA, GPIO_PIN_2);
		TaskDelay(500);
	}
}
void Task3_Handelr(void)
{
	while(1)
	{
		GPIO_u8TogglePinValue(GPIO_PORTA, GPIO_PIN_3);
		TaskDelay(250);
	}
}
void Task4_Handelr(void)
{
	while(1)
	{
		GPIO_u8TogglePinValue(GPIO_PORTA, GPIO_PIN_4);
		TaskDelay(125);
	}
}

