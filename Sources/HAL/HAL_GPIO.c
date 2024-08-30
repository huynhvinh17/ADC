/**
 * @file HAL_GPIO.c
 * @author huynhvinh17@gmail.com
 * @brief Hardware Abstraction Layer (HAL) for GPIO operations.
 * @version 0.1
 * @date 2024-08-20
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "../Includes/HAL/HAL_GPIO.h"

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
 * @brief Initializes a GPIO pin as an input or output
 *
 * @param GPIOx Pointer to the GPIO port structure
 * @param pin pin number on the specified GPIO port
 * @param pinState The state of pin:
 *                 - `configPinOutput`: Configures the pin as an output.
 *                 - `configPinInput`: Configures the pin as an input.
 */
void HAL_GPIO_Init(GPIO_Type *GPIOx, uint32_t pin, HAL_config_pin_t pinState)
{
    uint32_t pinMask = (1 << pin); /** Create a mask to the bit corresponding  */

    if (pinState == configPinOutput)
    {
        GPIOx->PDDR |= pinMask; /** Set the pin direction to output */
    }
    else if (pinState == configPinInput)
    {
        GPIOx->PDDR &= ~pinMask; /** Set the pin direction to input */
    }
}

/**
 * @brief Toggles the state of a specified GPIO pin
 *
 * @param GPIOx pointer to the GPIO port structure
 * @param pin pin number on the specified GPIO port
 */
void HAL_GPIO_TogglePin(GPIO_Type *GPIOx, uint32_t pin)
{
    uint32_t pinMask = (1 << pin); /** Create a mask to the bit corresponding  */
    GPIOx->PTOR |= pinMask;      /** Tonggle the state of the pin */
}

/**
 * @brief Writes a specified state to a GPIO pin
 *
 * @param GPIOx Pointer to the GPIO port structure
 * @param pin Pin number on the specified GPIO port
 * @param pinState The state of the pin
 *                  - `configPinHigh`: Sets the pin state to high (logic level 1).
 *                  - `configPinLow`: Sets the pin state to low (logic level 0).
 */
void HAL_GPIO_WritePin(GPIO_Type *GPIOx, uint32_t pin, HAL_pin_state_t pinState)
{
    uint32_t pinMask = (1 << pin);

    if (pinState == configPinHigh)
    {
        GPIOx->PDOR &= ~pinMask; /** Set the pin state to high */
    }
    else if (pinState == configPinLow)
    {
        GPIOx->PDOR |= pinMask; /** Set the pin state to low */
    }
}
