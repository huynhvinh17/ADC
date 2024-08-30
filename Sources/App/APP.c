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

void ADC0_Init(void)
{
    DRIVER_SIM_SCGC5_EnableClock(PORTE_clockEnable);
    DRIVER_SIM_SCGC6_EnableClock(ADC0_clockEnable);
    DRIVER_PORT_Init(PORTE, LIGHT_SENSOR, Pin_analog);
    HAL_ADC0_CFG1(convert16Bit, busClock);
    HAL_ADC0_SC2(software_trigger);
    DRIVER_NVIC_EnableIRQ(ADC0_IRQn);
}

void config_Led_LIGHT(uint16_t adc_value)
{
    float light_percentage;
    light_percentage = ADC_to_Percentage(adc_value);

    if (light_percentage > 70)
    {
        HAL_GPIO_WritePin(GPIOD, LED_GREEN_PIN, configPinHigh);
        HAL_GPIO_WritePin(GPIOE, LED_RED_PIN, configPinHigh);
    }
    else
    {
        HAL_GPIO_WritePin(GPIOD, LED_GREEN_PIN, configPinLow);
        HAL_GPIO_WritePin(GPIOE, LED_RED_PIN, configPinLow);
    }
}

void ADC0_Read(uint8_t channel)
{
    HAL_ADC0_SC1(0, channel);
    while (!(ADC0->SC1[0] & ADC_SC1_COCO_MASK))
    {
    };
}
