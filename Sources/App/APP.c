/**
 * @file APP.c
 * @author huynhvinh17@gmail.com
 * @brief Application layer for initializing LEDs and switches, and handling interrupts.
 * @version 0.1
 * @date 2024-08-20
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "../Includes/APP/APP.h"

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
 * @brief Initializes the green LED on PORTD
 *
 */
void Init_LED_Green(void)
{
    DRIVER_SIM_SCGC5_EnableClock(PORTD_clockEnable);          /** Enable the clock for PORTD */
    DRIVER_PORT_Init(PORTD, LED_GREEN_PIN, Pin_GPIO);         /** Initialize PORTD for GPIO functionaliy */
    DRIVER_GPIO_Init(GPIOD, LED_GREEN_PIN, configPinOutput);  /** Set the green LED pin as an output*/
    DRIVER_GPIO_WritePin(GPIOD, LED_GREEN_PIN, configPinLow); /** Set the green LED pin to low (led off) */
}

/**
 * @brief Initializes the red LED on PORTE
 *
 */
void Init_LED_Red(void)
{
    DRIVER_SIM_SCGC5_EnableClock(PORTE_clockEnable);        /** Enable the clock for PORTE */
    DRIVER_PORT_Init(PORTE, LED_RED_PIN, Pin_GPIO);         /** Initialize PORTE for GPIO functionality */
    DRIVER_GPIO_Init(GPIOE, LED_RED_PIN, configPinOutput);  /** Set the red LED pin as an output */
    DRIVER_GPIO_WritePin(GPIOE, LED_RED_PIN, configPinLow); /** Set the red LED pin to low (LED off) */
}

/**
 * @brief Initialize the ADC conversion
 *
 */
void ADC0_Init(void)
{
    DRIVER_SIM_SCGC5_EnableClock(PORTE_clockEnable);   /** Enable the clock for PORT E */
    DRIVER_SIM_SCGC6_EnableClock(ADC0_clockEnable);    /** Enable the clock for the ADC0 module */
    DRIVER_PORT_Init(PORTE, LIGHT_SENSOR, Pin_analog); /** Initialize the pin connected to the light sensor */
    HAL_ADC0_ConfigRegister1(convert16Bit, busClock);  /** Configure ADC0 for 16bit conversion */
    HAL_ADC0_StatusAndControl2(software_trigger);      /** Set ADC0 to software triggering for conversion */
    DRIVER_NVIC_EnableIRQ(ADC0_IRQn);                  /** Enable the ADC0 interrupt in the NVIC */
}

/**
 * @brief Configures and controls the LEDs based on the ADC value.
 *
 * @param adc_value The ADC value representing the light sensor's input
 */
void config_Led_LIGHT(uint16_t adc_value)
{
    float light_percentage;
    light_percentage = ADC_to_Percentage(adc_value); /** Convert the ADC value to a percentage */

    /** If the light percentageis greater than 40%, turn on both the green and led REDs */
    if (light_percentage > 40)
    {
        HAL_GPIO_WritePin(GPIOD, LED_GREEN_PIN, configPinHigh); /** Turn on green LED */
        HAL_GPIO_WritePin(GPIOE, LED_RED_PIN, configPinHigh);   /** Turn on red LED */
    }
    else
    {
        HAL_GPIO_WritePin(GPIOD, LED_GREEN_PIN, configPinLow); /** Turn off green LED */
        HAL_GPIO_WritePin(GPIOE, LED_RED_PIN, configPinLow);   /** Turn off red LED */
    }
}

/**
 * @brief Initiates an ADC conversion on the specified channel
 *
 * @param channel The ADC input channel to read
 */
void ADC0_Read(DRIVER_input_channel_t channel)
{
    DRIVER_ADC0_StatusAndControl1(channel, enable_interrupt); /** Start an ADC conversion on the specified channel with interrupts enable */
}
