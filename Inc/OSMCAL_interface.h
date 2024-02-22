/*
 * STK_interface.h
 *
 *  Created on: Feb 14, 2024
 *      Author: El-Wattaneya
 */

#ifndef STK_INTERFACE_H_
#define STK_INTERFACE_H_
#include <OSMCAL_config.h>
#include "stm32f103.h"
#include "main.h"
#define DUMMY_xPSR              0x01000000U
#define DUMMY_LR                0XFFFFFFFDU

#define ENTER_CRITICAL_SECTION()    do{__asm volatile("MOV R0,#1"); __asm volatile("MSR PRIMASK,R0");}while(0)

#define EXIT_CRITICAL_SECTION()		do{__asm volatile("MOV R0,#0"); __asm volatile("MSR PRIMASK,R0");}while(0)
typedef enum{
	READY_STATE,
	BLOCK_STATE
}TaskState_t;

typedef struct{
	uint32_t PSPvalue;
	uint32_t BlockCount;
	TaskState_t State;
	void (*TaskHandler)(void);
}TCB_t;




__attribute__ ((naked)) void Stack_voidSchedulerStackInit(uint32_t Copy_u32SchedTOS);
void Stack_voidTaskStackInit();
void STk_voidInit(uint32_t copy_u8TickHz);
__attribute__ ((naked)) void ChangeToPSP(void);
void EnableSysFualts();
void TaskDelay(uint32_t Copy_u3Blockingcount);

#endif /* STK_INTERFACE_H_ */
