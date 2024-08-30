/**
 * @file HAL_SIM.c
 * @author huynhvinh17@gmail.com
 * @brief Hardware Abstraction Layer (HAL) for System Integration Module (SIM) clock control.
 * @version 0.1
 * @date 2024-08-20
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "../Includes/HAL/HAL_SIM.h"

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
 * @brief Enable clock for a peripheral port
 *
 * @param portClockEnable The clock enable bit mask for peripheral port
 */
void HAL_SIM_SCGC5_EnableClock(HAL_port_SCGC5_clock_control_t portClockEnable)
{
    SIM->SCGC5 |= portClockEnable; /** Enable clock for specific peripheral port */
}

void HAL_SIM_SCGC6_EnableClock(HAL_SCGC6_clock_control_t ClockEnable)
{
    SIM->SCGC6 |= ClockEnable;
}
