#ifndef _DRIVER_NVIC_
#define _DRIVER_NVIC_

#include "MKL46Z4.h"
#include "stdint.h"
#include "../Includes/HAL/HAL_NVIC.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*******************************************************************************
 * Prototype
 ******************************************************************************/

/**
 * @brief Enables the interrupt for a IRQ number
 *
 * @param irq_number The IRQ number to be enable
 */
void DRIVER_NVIC_EnableIRQ(IRQn_Type irq_number);

/*******************************************************************************
 * Code
 ******************************************************************************/

#endif /** _DRIVER_NVIC_ */
