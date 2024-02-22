/*************************************************************************/
/****     file      : GPIO_interface.h                                ****/
/****     Target    : STM32F103C8T6                                   ****/
/****     Author    : Mahmoud Abdelmoniem                             ****/
/****     Date      : 1/2024                                          ****/
/****     version    : 0.0                                            ****/
/*************************************************************************/

#ifndef GPIO_INTERFACE_H_
#define GPIO_INTERFACE_H_

#include "ErrType.h"
#include <stdint.h>
#include "Bit_math.h"
#include "stm32f103.h"
#include "GPIO_private.h"

#define NULL       (void*)0
#define OUTPUT_MAX_SPEED_10_MHz       0x01
#define OUTPUT_MAX_SPEED_2_MHz        0x02
#define OUTPUT_MAX_SPEED_50_MHz        0x03

typedef enum{

	GPIO_PORTA,
	GPIO_PORTB,
	GPIO_PORTC,
	GPIO_PORTD,
	GPIO_PORTE

}Port_t;
typedef enum{
	GPIO_PIN_0=0,
	GPIO_PIN_1,
	GPIO_PIN_2,
	GPIO_PIN_3,
	GPIO_PIN_4,
	GPIO_PIN_5,
	GPIO_PIN_6,
	GPIO_PIN_7,
	GPIO_PIN_8,
	GPIO_PIN_9,
	GPIO_PIN_10,
	GPIO_PIN_11,
	GPIO_PIN_12,
	GPIO_PIN_13,
	GPIO_PIN_14,
	GPIO_PIN_15

}Pin;

typedef enum{
	GP_PUSH_PULL,         /*GPIO PIN output mode push pull general purpose*/
	GP_OPEN_DRAIN,        /*GPIO PIN output mode open drain general purpose*/
	AF_PUSH_PULL,         /*GPIO PIN output mode push pull Alternative function*/
	AF_OPEN_DRAIN         /*GPIO PIN output mode open drain Alternative function*/
}Output_ModeType_t;


typedef enum{
	ANALOG,
	FLOATING,
	INPUT_PULL_UP_DOWN,
	RESERVED
}Input_ModeType_t;


typedef enum{
	GPIO_INPUT,
	GPIO_OUTPU
}Mode_t;

typedef enum{
	PULL_DOWN,
	PULL_UP
}Input_Pull_t;

typedef enum{
	GPIO_LOW,
	GPIO_HIGH
}GPIO_PinSts;
typedef struct{
	Port_t Port;
	Pin    PinNum;
	Mode_t Mode;
	Output_ModeType_t Outmode;
	Input_ModeType_t InMode;
	Input_Pull_t Pull;
	uint8_t OutMaxSpeed;
}PinConfig_t;


uint8_t GPIO_u8PinInit(const PinConfig_t * pinconfg);
uint8_t GPIO_u8SetPinValue(Port_t port,Pin pinNum,GPIO_PinSts pinStatus);
uint8_t GPIO_u8TogglePinValue(Port_t port,Pin pinNum);
uint8_t GPIO_u8GetPinValue(Port_t port,Pin pinNum,GPIO_PinSts *pinStatus);


#endif /* GPIO_INTERFACE_H_ */
