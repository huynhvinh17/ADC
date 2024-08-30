#include "../Includes/DRIVER/DRIVER_Software_timer.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*******************************************************************************
 * Prototype
 ******************************************************************************/

/*******************************************************************************
 * Code
 ******************************************************************************/

/**
 * @brief Initializes the software timers
 */
void DRIVER_Software_Timer_Init(void)
{
    uint8_t i;
    for (i = 0; i < MAX_TIMERS; i++)
    {
        swTimerArray[i].Current_value = 0; /** Reset current value to 0 */
        swTimerArray[i].Load_value = 0;    /** Set the initial load value to 0  */
        swTimerArray[i].func = NULL;       /** initialize the function pointer to NULL */
        swTimerArray[i].en = false;        /** Disable the timer */
    }
    HAL_Systick_init(0xFFFFF); /** Start the Systick timer with a load value of 0xFFFFF */
}

/**
 * @brief Enable the software timer
 *
 * @param timerIndex The index of software timer to enable
 */
void DRIVER_Software_Timer_Enable(uint8_t timerIndex)
{
    if (timerIndex < MAX_TIMERS) /** Check if the timer index */
    {
        swTimerArray[timerIndex].en = true; /** Enable the software timer */
    }
    else
    {
        /** do nothing */
    }
}

/**
 * @brief Disable the software timer
 *
 * @param timerIndex The index of software timer to disable
 */
void DRIVER_Software_Timer_Disable(uint8_t timerIndex)
{
    if (timerIndex < MAX_TIMERS) /** Check if the timer index */
    {
        swTimerArray[timerIndex].en = false; /** Disable the software timer */
    }
    else
    {
        /** do nothing */
    }
}

/**
 * @brief Checks and handles all software timers.
 */
void DRIVER_Software_timer_check_and_handle()
{
    uint8_t i;

    /** Loop through all possible timers */
    for (i = 0; i < MAX_TIMERS; i++)
    {
        /** check if the index is valid range */
        if (i < MAX_TIMERS)
        {
            /** Check if the current timer is enabled */
            if (swTimerArray[i].en)
            {
                /** Increment the current value of the timer */
                swTimerArray[i].Current_value++;

                /** Check if the timer equal load value  */
                if (swTimerArray[i].Current_value >= swTimerArray[i].Load_value)
                {
                    /** if a callback function is define */
                    if (swTimerArray[i].func != NULL)
                    {
                        swTimerArray[i].func(); /** Execute the callback */
                    }

                    /** Reset the current value to restart the timer */
                    swTimerArray[i].Current_value = 0;
                }
            }
        }
    }
}

/**
 * @brief Sets the load value
 *
 * @param timerIndex Index of the software timer to configure
 * @param loadValue The value to set
 */
void DRIVER_Software_timer_set_value(uint8_t timerIndex, uint32_t loadValue)
{
    /** Check if the timer index is the valid range */
    if (timerIndex < MAX_TIMERS)
    {
        swTimerArray[timerIndex].Load_value = loadValue; /** Set the load value */
    }
}

/**
 * @brief Registers a user defined callback function
 *
 * @param timerIndex Index of the software timer to register
 * @param user Pointer to the user-defined
 */
void DRIVER_Software_timer_register_callbackUser(uint8_t timerIndex, SW_timer_callback_t user)
{
    /** check if the timer index is the valid range */
    if (timerIndex < MAX_TIMERS)
    {
        swTimerArray[timerIndex].func = user; /** Register the user define callback function */
    }
}