#ifndef _HAL_SYSTICK_
#define _HAL_SYSTICK_

#include "stdint.h"
#include "MKL46Z4.h"

/**
 * @brief Initializes the Systick timer
 *
 * @param loadValue The value to be loaded into the Systick
 */
void HAL_Systick_init(uint32_t loadValue);

/**
 * @brief Deinitializes the Systick timer
 */
void HAL_Systick_deinit(void);

#endif /** _HAL_SYSTICK_ */
