#include "../Includes/HAL/HAL_Systick.h"

/**
 * @brief Initializes the Systick timer
 *
 * @param loadValue The value to be loaded into the Systick
 */
void HAL_Systick_init(uint32_t loadValue)
{
    SysTick->VAL = 0;                                                                                 /** Clear the current value register to reset */
    SysTick->LOAD = loadValue;                                                                        /** Set the reload value to the specìied */
    SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk | SysTick_CTRL_CLKSOURCE_Msk | SysTick_CTRL_TICKINT_Msk; /** Enable systick timer, use the processor clock, enable Systick exception */
}

/**
 * @brief Deinitializes the Systick timer
 */
void HAL_Systick_deinit(void)
{
    SysTick->CTRL |= (SysTick_CTRL_ENABLE_Pos | SysTick_CTRL_TICKINT_Pos); /** Disable the Systick timer, disable systick exception */
}
