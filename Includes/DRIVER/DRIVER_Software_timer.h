#ifndef _DRIVER_SOFTWARE_TIMER_
#define _DRIVER_SOFTWARE_TIMER_

#include "../Includes/HAL/HAL_Systick.h"
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

/*******************************************************************************
 * Definitions
 ******************************************************************************/

#define MAX_TIMERS 10

/*******************************************************************************
 * Prototype
 ******************************************************************************/

typedef void (*SW_timer_callback_t)(void);

typedef struct
{
    uint32_t Current_value;
    uint32_t Load_value;
    SW_timer_callback_t func;
    bool en;
} sw_timer;

sw_timer swTimerArray[MAX_TIMERS];

/**
 * @brief Initializes the software timers
 */
void DRIVER_Software_Timer_Init();

/**
 * @brief Enable the software timer
 *
 * @param timerIndex The index of software timer to enable
 */
void DRIVER_Software_Timer_Enable(uint8_t timerIndex);

/**
 * @brief Disable the software timer
 *
 * @param timerIndex The index of software timer to disable
 */
void DRIVER_Software_Timer_Disable(uint8_t timerIndex);

/**
 * @brief Checks and handles all software timers.
 */
void DRIVER_Software_timer_check_and_handle(void);

/**
 * @brief Sets the load value
 *
 * @param timerIndex Index of the software timer to configure
 * @param loadValue The value to set
 */
void DRIVER_Software_timer_set_value(uint8_t timerIndex, uint32_t loadValue);

/**
 * @brief Registers a user defined callback function
 *
 * @param timerIndex Index of the software timer to register
 * @param user Pointer to the user-defined
 */
void DRIVER_Software_timer_register_callbackUser(uint8_t timerIndex, SW_timer_callback_t user);

/*******************************************************************************
 * Code
 ******************************************************************************/

#endif /** _DRIVER_SOFTWARE_TIMER_ */
