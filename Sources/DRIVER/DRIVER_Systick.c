#include "../Includes/DRIVER/DRIVER_Systick.h"
#include "MKL46Z4.h"
#include <stdint.h>
#include <stddef.h>

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*******************************************************************************
 * Prototype
 ******************************************************************************/

/** Declare a global function pointer of type func_DRIVER_sw_timer_handler */
func_DRIVER_sw_timer_handler DRIVER_sw_timer_handler = NULL;

/** Enumeration value representing the state of the `count_flag_t` */
typedef enum
{
    countFlagLow, /** Representing the low state */
    countFlagHigh /** Representing the high state */
} count_flag_t;

/** Declare and initialize countFlag to countFlagLow */
uint8_t countFlag = countFlagLow;

/*******************************************************************************
 * Code
 ******************************************************************************/

/**
 * @brief handle systick interrupts
 *
 * @param sw_call function pointer to be assigned to DRIVER_sw_timer_handler
 */
void systick_interrupt_handlerFunctionCall(func_DRIVER_sw_timer_handler sw_call)
{
    DRIVER_sw_timer_handler = sw_call; /** Assign the function pointer sw_call to the global DRIVER_sw_timer_handler pointer */
}

/**
 * @brief Systick interrupt service routine
 */
void SysTick_Handler(void)
{
    /**  Check if the SysTick COUNTFLAG is set. */
    if (SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk)
    {
        countFlag = countFlagHigh; /** Set countFlag to countFlagHigh */
    }
    else
    {
        countFlag = countFlagLow; /** Set countFlag to countFlagLow */
    }
}

void DRIVER_sw_timer_handlerCall(void)
{
    if (DRIVER_sw_timer_handler != NULL)
    {
        DRIVER_sw_timer_handler();
    }
}

/**
 * @brief Return the current state of the countFlag
 *
 * @return uint8_t The current value of countFlag
 */
uint8_t countFlagReturn(void)
{
    return countFlag; /** Return the current value of countFlag. */
}
