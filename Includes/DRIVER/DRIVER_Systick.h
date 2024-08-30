#ifndef _DRIVER_SYSTICK_
#define _DRIVER_SYSTICK_

#include "../Includes/DRIVER/DRIVER_Software_timer.h"
#include <stdint.h>

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*******************************************************************************
 * Prototype
 ******************************************************************************/

/**
 * @brief
 */
typedef void (*func_DRIVER_sw_timer_handler)(void);

/**
 * @brief handle systick interrupts
 *
 * @param sw_call function pointer to be assigned to DRIVER_sw_timer_handler
 */
void systick_interrupt_handlerFunctionCall(func_DRIVER_sw_timer_handler sw_call);

/**
 * @brief Return the current state of the countFlag
 *
 * @return uint8_t The current value of countFlag
 */
uint8_t countFlagReturn(void);

void DRIVER_sw_timer_handlerCall(void);

/*******************************************************************************
 * Code
 ******************************************************************************/

#endif /** _DRIVER_SYSTICK_ */