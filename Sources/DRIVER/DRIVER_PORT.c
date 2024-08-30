/**
 * @file DRIVER_PORT.c
 * @author huynhvinh17@gmail.com
 * @brief PORT driver implementation for configuring and handling GPIO ports and interrupts.
 * @version 0.1
 * @date 2024-08-20
 *
 * @copyright Copyright (c) 2024
 *
 */


#include "../Includes/DRIVER/DRIVER_PORT.h"

uint16_t adc_value;

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*******************************************************************************
 * Prototype
 ******************************************************************************/

/*******************************************************************************
 * Code
 ******************************************************************************/

/** Declare and initialize a pointer to a callback function for handling PORTC and PORTD interrupts */
ADC0_callback_t ADC0_callback = NULL;
/**
 * @brief The interrupt flag status for the specific GPIO pin
 *
 * @param PORT pointer to the PORT structure
 * @param pin The pin number on the specified PORT
 * @return uint32_t The interrupt flag status
 */
uint32_t DRIVER_PORT_GetInterruptFlag(PORT_Type *PORT, uint32_t pin)
{
    return HAL_PORT_GetInterruptFlag(PORT, pin); /**    Call the HAL function to get the interrupt flag */
}

/**
 * @brief Clears the interrupt flag for a specific GPIO pin
 *
 * @param PORT Pointer to the PORT structure
 * @param pin The pin number on the specified PORT
 */
void DRIVER_PORT_ClearInterruptFlag(PORT_Type *PORT, uint32_t pin)
{
    HAL_PORT_ClearInterruptFlag(PORT, pin); /** Call the HAL function to clear the interrupt flag*/
}

/**
 * @brief Initializes a GPIO pin with a specific configuration
 *
 * @param PORT Pointer to the PORT structure
 * @param pin The pin number on the specific PORT
 * @param config The pin configuration setting
 */
void DRIVER_PORT_Init(PORT_Type *PORT, uint32_t pin, DRIVER_pin_mux_control_t config)
{
    HAL_PORT_Init(PORT, pin, config); /** Call the HAL function to initialize the pin */
}

/**
 * @brief Configures the interrupt settings
 *
 * @param PORT Pointer to the PORT structure
 * @param pin The pin number on the specified PORT
 * @param config The interrupt configuration settings
 */
void DRIVER_PORT_InterruptConfig(PORT_Type *PORT, uint32_t pin, DRIVER_interrupt_config_t config)
{
    HAL_PORT_InterruptConfig(PORT, pin, config); /** Call the HAL function configure the interrupt setting */
}

/**
 * @brief Configures the pull-up/pull-down resistors for a specific GPIO pin
 *
 * @param PORT Pointer to the PORT structure
 * @param pin The pin number on the specific PORT
 * @param enable To enable or disable the internal pulll-up/pull-down resistor
 * @param select which type of pull resistor to use:
 *                - `pullUp`: Selects the pull-up resistor.
 *                - `pullDown`: Selects the pull-down resistor.
 */
void DRIVER_PORT_PullResistor(PORT_Type *PORT, uint32_t pin, DRIVER_pull_enable_t enable, DRIVER_pull_select_t select)
{
    HAL_PORT_PullEnable(PORT, pin, enable); /** Call HAL function to enable or disable pull resistor */
    HAL_PORT_PullSelect(PORT, pin, select); /** Call HAL function to select pull-up or pull-down resistor */
}

/**
 * @brief Ngắt xử lý ADC
 */
void ADC0_IRQHandler(void)
{
    adc_value = HAL_ADC0_dataReturn();
}

uint16_t ADC_returnValue()
{
    return adc_value;
}
