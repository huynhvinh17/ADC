/**
 * @file DRIVER_GPIO.c
 * @author huynhvinh17@gmail.com
 * @brief GPIO driver implementation for initializing and controlling GPIO pins.
 * @version 0.1
 * @date 2024-08-20
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "../Includes/DRIVER/DRIVER_GPIO.h"

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
 * @brief Initializes a GPIO pin with a specified state
 *
 * @param GPIOx Pointer to the GPIO port structure
 * @param pin The pin number on the GPIO port
 * @param pinState State of the pin
 */
void DRIVER_GPIO_Init(GPIO_Type *GPIOx, uint32_t pin, DRIVER_pin_state_t pinState)
{
    HAL_GPIO_Init(GPIOx, pin, pinState); /** Call the HAL function to initialize the pin */
}

/**
 * @brief Tonggle the state of a GPIO pin
 *
 * @param GPIOx Pointer to the GPIO port structure
 * @param pin The pin number on the GPIO port
 */
void DRIVER_GPIO_TogglePin(GPIO_Type *GPIOx, uint32_t pin)
{
    HAL_GPIO_TogglePin(GPIOx, pin); /** Call the HAL function to tonggle the state of the pin  */
}

/**
 * @brief Writes a specified state to a GPIO pin
 *
 * @param GPIOx Pointer to the GPIO port structure
 * @param pin The pin number on the GPIO port
 * @param pinState The state of pin
 *                 - `configPinHigh`: Sets the pin state to high (logic level 1).
 *                 - `configPinLow`: Sets the pin state to low (logic level 0).
 */
void DRIVER_GPIO_WritePin(GPIO_Type *GPIOx, uint32_t pin, DRIVER_pin_state_t pinState)
{
    HAL_GPIO_WritePin(GPIOx, pin, pinState); /** Call the HAL function to write the specified state to the pin */
}
