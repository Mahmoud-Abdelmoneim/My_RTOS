/*
 * STK_config.h
 *
 *  Created on: Feb 14, 2024
 *      Author: El-Wattaneya
 */

#ifndef OSMCAL_CONFIG_H_
#define OSMCAL_CONFIG_H_

#define HSI_CLOCK               8000000UL
#define SYSTICK_TIM_CLK       HSI_CLOCK


#define NUMBER_OF_TASKS     5



#define SIZE_TASK_STACK          1024U
#define SIZE_SCHEDULER_STACK     1024U

#define SRAM_START            0x20000000
#define SRAM_SIZE             (20*1024)

#define SRAM_END              ((SRAM_START) + (SRAM_SIZE))


#define T1_STACK_START        SRAM_END
#define T2_STACK_START        (SRAM_END - SIZE_TASK_STACK)
#define T3_STACK_START        (SRAM_END - (SIZE_TASK_STACK *2))
#define T4_STACK_START        (SRAM_END - (SIZE_TASK_STACK *3))
#define IDLE_TASK_STACK_START (SRAM_END - (SIZE_TASK_STACK *4))
#define SCHEDULER_STACK_START (SRAM_END - (SIZE_SCHEDULER_STACK *5))






#endif /* OSMCAL_CONFIG_H_ */
