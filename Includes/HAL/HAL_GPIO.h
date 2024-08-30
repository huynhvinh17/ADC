#ifndef _HAL_GPIO_H_
#define _HAL_GPIO_H_

#include "MKL46Z4.h"
#include "HAL_PORT.h"
#include "stdint.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*******************************************************************************
 * Prototype
 ******************************************************************************/

/**
 * @brief Enumeration for GPIO pin configuration states
 *
 */
typedef enum
{
    configPinInput, /** Configures the pin as an input */
    configPinOutput /** Configures the pin as an outpur */
} HAL_config_pin_t;

/** Enumeration for GPIO pin state */
typedef enum
{
    configPinLow, /** Set the pin to a low state */
    configPinHigh /** Set the pin to a hige state */
} HAL_pin_state_t;

/**
 * @brief Initializes a GPIO pin as an input or output
 *
 * @param GPIOx Pointer to the GPIO port structure
 * @param pin pin number on the specified GPIO port
 * @param pinState The state of pin:
 *                 - `configPinOutput`: Configures the pin as an output.
 *                 - `configPinInput`: Configures the pin as an input.
 */
void HAL_GPIO_Init(GPIO_Type *GPIOx, uint32_t pin, HAL_config_pin_t pinState);

/**
 * @brief Toggles the state of a specified GPIO pin
 *
 * @param GPIOx pointer to the GPIO port structure
 * @param pin pin number on the specified GPIO port
 */
void HAL_GPIO_TogglePin(GPIO_Type *GPIOx, uint32_t pin);

/**
 * @brief Writes a specified state to a GPIO pin
 *
 * @param GPIOx Pointer to the GPIO port structure
 * @param pin Pin number on the specified GPIO port
 * @param pinState The state of the pin
 *                  - `configPinHigh`: Sets the pin state to high (logic level 1).
 *                  - `configPinLow`: Sets the pin state to low (logic level 0).
 */
void HAL_GPIO_WritePin(GPIO_Type *GPIOx, uint32_t pin, HAL_pin_state_t pinState);

/*******************************************************************************
 * Code
 ******************************************************************************/

#endif /** _HAL_GPIO_H_ */
