/**
 * @file HAL_PORT.c
 * @author huynhvinh17@gmail.com
 * @brief Hardware Abstraction Layer (HAL) for Port operations.
 * @version 0.1
 * @date 2024-08-20
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "../Includes/HAL/HAL_PORT.h"

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
 * @brief check if an interrupt has been triggered
 *
 * @param PORT Pointer to the port structure
 * @param pin Pin number on the specified port
 * @return uint32_t non-zero value if a interrupt has been triggered
 */
uint32_t HAL_PORT_GetInterruptFlag(PORT_Type *PORT, uint32_t pin)
{
    uint32_t pinMask = (1 << pin); /** Create bit mask for the specified pin */

    return PORT->ISFR & pinMask; /** Return the status of the interrupt flag */
}

/**
 * @brief Clear flag after an interrupt is triggered
 *
 * @param PORT Pointer to the port structure
 * @param pin Pin number on the specified port
 */
void HAL_PORT_ClearInterruptFlag(PORT_Type *PORT, uint32_t pin)
{
    uint32_t pinMask = (1 << pin);

    PORT->ISFR |= pinMask;
}

/**
 * @brief Initialize the pin mux configuration
 *
 * @param PORT Pointer to the port structure
 * @param pin Pin number on the specified port
 * @param config The pin mux configuration value to set for the pin
 */
void HAL_PORT_Init(PORT_Type *PORT, uint32_t pin, HAL_pin_mux_control_t config)
{
    PORT->PCR[pin] &= ~PORT_PCR_MUX_MASK; /** Clear the existing pin mux setting */
    PORT->PCR[pin] |= config;             /** Set the new pin mux configuration */
}

/**
 * @brief Configures the interrupt setting
 *
 * @param PORT Pointer to the port structure
 * @param pin Pin number on the specified port
 * @param config The interrupt configuration value to be set
 */
void HAL_PORT_InterruptConfig(PORT_Type *PORT, uint32_t pin, HAL_interrupt_config_t config)
{
    PORT->PCR[pin] &= ~PORT_PCR_IRQC_MASK; /**  Clear the IRQC field */
    PORT->PCR[pin] |= config;              /**  Set the new interrupt configuration */
}

/**
 * @brief Configure the internal pull up or pull down resistor
 *
 * @param PORT Pointer to the port structure
 * @param pin Pin number on the specified port
 * @param enable Specifies whether to enable or disble the internal pull resistor
 */
void HAL_PORT_PullEnable(PORT_Type *PORT, uint32_t pin, HAL_pull_enable_t enable)
{
    if (enable == enable_internal_pull_pin)
    {
        PORT->PCR[pin] |= PORT_PCR_PE_MASK; /**  Enable internal pull-up or pull-down resistor */
    }
    else
    {
        PORT->PCR[pin] &= ~PORT_PCR_PE_MASK; /**  Disable internal pull-up or pull-down resistor */
    }
}

/**
 * @brief Selects the type of internal pull resistor
 *
 * @param PORT Pointer to the port structure
 * @param pin Pin number on the specified port
 * @param select Specifies whether to select a pull up or pull down resistor
 */
void HAL_PORT_PullSelect(PORT_Type *PORT, uint32_t pin, HAL_pull_select_t select)
{
    if (select == pullUp)
    {
        PORT->PCR[pin] |= PORT_PCR_PS_MASK; /**  Select pull-up resistor */
    }
    else
    {
        PORT->PCR[pin] &= ~PORT_PCR_PS_MASK; /**  Select pull-down resistor */
    }
}
