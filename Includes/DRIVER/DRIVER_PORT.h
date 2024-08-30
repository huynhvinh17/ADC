#ifndef _DRIVER_PORT_H_
#define _DRIVER_PORT_H_

#include <stddef.h>
#include "MKL46Z4.h"
#include "../Includes/HAL/HAL_PORT.h"
#include "../Includes/HAL/HAL_ADC.h"
#include "stdint.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*******************************************************************************
 * Prototype
 ******************************************************************************/

/** Typedef for a callback function pointer type used for PORTC and PORTD interrupts. */
typedef void (*ADC0_callback_t)(void);

typedef HAL_pin_mux_control_t DRIVER_pin_mux_control_t;   /** defined as an alias for the type `HAL_pin_mux_control_t` */
typedef HAL_interrupt_config_t DRIVER_interrupt_config_t; /** defined as an alias for the type `HAL_interrupt_config_t` */
typedef HAL_pull_select_t DRIVER_pull_select_t;           /** defined as an alias for the type `HAL_pull_select_t` */
typedef HAL_pull_enable_t DRIVER_pull_enable_t;           /** defined as an alias for the type `HAL_pull_enable_t` */

/**
 * @brief The interrupt flag status for the specific GPIO pin
 *
 * @param PORT pointer to the PORT structure
 * @param pin The pin number on the specified PORT
 * @return uint32_t The interrupt flag status
 */
uint32_t DRIVER_PORT_GetInterruptFlag(PORT_Type *PORT, uint32_t pin);

/**
 * @brief Clears the interrupt flag for a specific GPIO pin
 *
 * @param PORT Pointer to the PORT structure
 * @param pin The pin number on the specified PORT
 */
void DRIVER_PORT_ClearInterruptFlag(PORT_Type *PORT, uint32_t pin);

/**
 * @brief Initializes a GPIO pin with a specific configuration
 *
 * @param PORT Pointer to the PORT structure
 * @param pin The pin number on the specific PORT
 * @param config The pin configuration setting
 */
void DRIVER_PORT_Init(PORT_Type *PORT, uint32_t pin, DRIVER_pin_mux_control_t config);

/**
 * @brief Configures the interrupt settings
 *
 * @param PORT Pointer to the PORT structure
 * @param pin The pin number on the specified PORT
 * @param config The interrupt configuration settings
 */
void DRIVER_PORT_InterruptConfig(PORT_Type *PORT, uint32_t pin, DRIVER_interrupt_config_t config);

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
void DRIVER_PORT_PullResistor(PORT_Type *PORT, uint32_t pin, DRIVER_pull_enable_t enable, DRIVER_pull_select_t select);

uint16_t ADC_returnValue();

/*******************************************************************************
 * Code
 ******************************************************************************/

#endif /** _DRIVER_PORT_H_ */
