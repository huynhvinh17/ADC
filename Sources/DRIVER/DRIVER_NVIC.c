/**
 * @file DRIVER_NVIC.c
 * @author huynhvinh17@gmail.com
 * @brief NVIC driver implementation for enabling interrupts
 * @version 0.1
 * @date 2024-08-20
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "../Includes/DRIVER/DRIVER_NVIC.h"

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
 * @brief Enables the interrupt for a IRQ number
 *
 * @param irq_number The IRQ number to be enable
 */
void DRIVER_NVIC_EnableIRQ(IRQn_Type irq_number)
{
    HAL_EnableIRQ(irq_number); /**  Call the HAL function to enable the interrupt */
}
