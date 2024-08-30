#ifndef _APP_H_
#define _APP_H_

#include "MKL46Z4.h"
#include "../Includes/DRIVER/DRIVER_GPIO.h"
#include "../Includes/DRIVER/DRIVER_NVIC.h"
#include "../Includes/DRIVER/DRIVER_PORT.h"
#include "../Includes/DRIVER/DRIVER_SIM.h"
#include "../Includes/DRIVER/DRIVER_Software_timer.h"
#include "../Includes/DRIVER/DRIVER_Systick.h"
#include "../Includes/HAL/HAL_ADC.h"
#include "stdio.h"
#include "stdint.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

#define LED_GREEN_PIN 5 /** Define pin number for led green */
#define LED_RED_PIN 29  /** Define pin number for led red */
#define LIGHT_SENSOR 22       /** Define pin number for Switch 1 */

/*******************************************************************************
 * Prototype
 ******************************************************************************/

/**
 * @brief Initializes the green LED on PORTD
 *
 */
void Init_LED_Green(void);

/**
 * @brief Initializes the red LED on PORTE
 *
 */
void Init_LED_Red(void);

void ADC0_Init(void);

void config_Led_LIGHT(uint16_t adc_value);

void ADC0_Read(uint8_t channel);

/*******************************************************************************
 * Code
 ******************************************************************************/

#endif /** _APP_H_ */
