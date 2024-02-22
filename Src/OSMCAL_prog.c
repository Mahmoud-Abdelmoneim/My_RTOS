/*
 * STK_prog.c
 *
 *  Created on: Feb 14, 2024
 *      Author: El-Wattaneya
 */

#include "OSMCAL_interface.h"
static uint32_t GetPSPvalue(void);
static void SavePSPvalue(uint32_t Copy_u32CurrentValePSP);
static void UpdateNextTask(void);
static void UnblockTasks();
static void IdelTask(void);
TCB_t UserTask[NUMBER_OF_TASKS];
uint8_t CurrentTask=1;    /*starting from 1 to ignore the idle task*/
uint32_t GlobalTickCount=0u;
__attribute__ ((naked)) void Stack_voidSchedulerStackInit(uint32_t Copy_u32SchedTOS)
{

	__asm volatile("MSR MSP,R0");
	__asm volatile("BX LR");
}
void Stack_voidTaskStackInit()
{

	UserTask[0].TaskHandler = &IdelTask;
	UserTask[1].TaskHandler = &Task1_Handelr;
	UserTask[2].TaskHandler = &Task2_Handelr;
	UserTask[3].TaskHandler = &Task3_Handelr;
	UserTask[4].TaskHandler = &Task4_Handelr;

	UserTask[0].PSPvalue = IDLE_TASK_STACK_START;
	UserTask[1].PSPvalue = T1_STACK_START;
	UserTask[2].PSPvalue = T2_STACK_START;
	UserTask[3].PSPvalue = T3_STACK_START;
	UserTask[4].PSPvalue = T4_STACK_START;


	for(uint8_t TaskNum=0;TaskNum<NUMBER_OF_TASKS;TaskNum++)
	{
		UserTask[TaskNum].State=READY_STATE;
		uint32_t *StackPointer= (uint32_t*)UserTask[TaskNum].PSPvalue;
		StackPointer--;

		*StackPointer=DUMMY_xPSR;    //xPSR
		StackPointer--;

		*StackPointer=(uint32_t)UserTask[TaskNum].TaskHandler;    //PC
		StackPointer--;

		*StackPointer=DUMMY_LR;    //LR
		StackPointer--;
		for(uint8_t RegNum=0;RegNum<12;RegNum++)
		{
			*StackPointer=0;    //Rx
			StackPointer--;
		}

		UserTask[TaskNum].PSPvalue = (uint32_t)StackPointer;

	}
}
void STk_voidInit(uint32_t copy_u8TickHz)
{
	/*Calculate the required number of ticks  */
	uint32_t Local_u32ReloadValu = SYSTICK_TIM_CLK / copy_u8TickHz;

	SYSTICK->RVR = Local_u32ReloadValu - 1 ;

	/*Enable systick Exception*/
	SYSTICK->CSR |=1<<1;
	/*Select systick clock source */
	SYSTICK->CSR |=1<<2;
	/*Enable systick timer*/
	SYSTICK->CSR |=1<<0;
}


__attribute__ ((naked)) void ChangeToPSP(void)
{
	/*1- Push the value of the LR to save it since we return to */
	__asm volatile("PUSH {LR}");
	/*2- branch to helper function store psp value to the R0*/
	__asm volatile("BL GetPSPvalue");
	/*3- Initialise the PSP register*/
	__asm volatile("MSR PSP,R0");
	/*4- pop the LR register value */
	__asm volatile("POP {LR}");
	/*5-change the control register value to switch to psp*/
	__asm volatile("MOV R0,#0X02");
	__asm volatile("MSR CONTROL,R0");
	/*6- Exit*/
	__asm volatile("BX LR");

}

void EnableSysFualts()
{
	SCB->SHCSR |= (1<<16);
	SCB->SHCSR |= (1<<17);
	SCB->SHCSR |= (1<<18);
}


__attribute__ ((naked)) void PendSV_Handler(void)
{
	/*1- Save context of the current task*/
		/*a- Get the PSP vale of the current task*/
		__asm volatile("MRS R0,PSP");

		/*b- Using this PSP value store SF2 (R4->R13)*/
		__asm volatile("STMDB R0!,{R4-R11}");

		__asm volatile("PUSH {LR}");
		/*Save the current value of PSP*/
		__asm volatile("BL SavePSPvalue");

	/*2- Retrieve context of the next task*/
		/*a- Decied which task should be run*/
		__asm volatile("BL UpdateNextTask");

		/*b- Get its PSP value */
		__asm volatile("BL GetPSPvalue");

		__asm volatile("POP {LR}");
		/*c- Using this PSP value, Retrieve the SF2 (R4->R13)*/
		__asm volatile("LDMIA R0!,{R4-R11}");


		/*d- Update the PSP value*/
		__asm volatile("MSR PSP,R0");

		/*e- Exit*/
		__asm volatile("BX LR");

}

static void UnblockTasks()
{
	for(uint8_t TaskNum=1;TaskNum<NUMBER_OF_TASKS;TaskNum++)
	{
		if(UserTask[TaskNum].State == BLOCK_STATE)
		{
			if(UserTask[TaskNum].BlockCount == GlobalTickCount)
			{
				UserTask[TaskNum].State = READY_STATE;
			}
		}
	}
}

 void SysTick_Handler(void)
{
	 /*1- Update the Global Tick Count */
	 GlobalTickCount++;
	 /*2- Update the next Task*/
	 UnblockTasks();
	 /*3- pend(trigger) the pendSV Exception*/
	 SCB->ICSR |=(1<<28);

}

static uint32_t GetPSPvalue(void)
{
	return UserTask[CurrentTask].PSPvalue;
}
static void SavePSPvalue(uint32_t Copy_u32CurrentValePSP)
{
	UserTask[CurrentTask].PSPvalue = Copy_u32CurrentValePSP;
}
static void UpdateNextTask(void)
{
	for(uint8_t TaskNum=0;TaskNum<NUMBER_OF_TASKS;TaskNum++)
	{
		CurrentTask++;
		CurrentTask= CurrentTask%NUMBER_OF_TASKS;
		if(UserTask[CurrentTask].State == READY_STATE && TaskNum != 0)
		{
			break;
		}

	}
	if(UserTask[CurrentTask].State != READY_STATE)
	{
		CurrentTask = 0;
	}

}

void TaskDelay(uint32_t Copy_u3Blockingcount)
{
	/*Idle task can't be blocked*/
	if(CurrentTask != 0){
		ENTER_CRITICAL_SECTION();
		/*update the task blocking period*/
		UserTask[CurrentTask].BlockCount = GlobalTickCount
				+ Copy_u3Blockingcount;
		/*update the task state */
		UserTask[CurrentTask].State = BLOCK_STATE;
		EXIT_CRITICAL_SECTION();
		/*call the scheduler by pend pendsv  */
		SCB->ICSR |=(1<<28);
	}


}


void IdelTask(void)
{
	while(1);
}
void BusFault_Handler()
{

}
void MemManage_Handler()
{

}
void UsageFault_Handler()
{

}
