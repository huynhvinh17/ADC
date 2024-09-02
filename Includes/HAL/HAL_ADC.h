#ifndef _HAL_ADC_H_
#define _HAL_ADC_H_

#include "MKL46Z4.h"
#include "stdbool.h"
#include "stdint.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*******************************************************************************
 * Prototype
 ******************************************************************************/

/**
 * @brief Enumeration for ADC input channels.
 *
 */
typedef enum input_channel
{
    DADP0_DAD0, /** Single-ended input channel DAD0. */
    DADP1_DAD1, /** Single-ended input channel DAD1. */
    DADP2_DAD2, /** Single-ended input channel DAD2. */
    DADP3_DAD3, /** Single-ended input channel DAD3. */
    AD4,        /** Single-ended input channel AD4. */
    AD5,        /** Single-ended input channel AD5. */
    AD6,        /** Single-ended input channel AD6. */
    AD7,        /** Single-ended input channel AD7. */
    AD8,        /** Single-ended input channel AD8. */
    AD9,        /** Single-ended input channel AD9. */
    AD10        /** Single-ended input channel AD10. */
} HAL_input_channel_t;

/**
 * @brief Enumeration for ADC conversion modes.
 *
 */
typedef enum mode
{
    convert8Bit,  /** 8-bit resolution ADC conversion. */
    convert12Bit, /** 12-bit resolution ADC conversion. */
    convert10Bit, /** 10-bit resolution ADC conversion. */
    convert16Bit, /** 16-bit resolution ADC conversion. */
} HAL_ADC_MODE_single_ended_t;

/**
 * @brief Enumeration for ADC bus clock sources.
 *
 */
typedef enum bus_clock
{
    busClock,        /** Use the bus clock as the ADC clock source. */
    busClockDivide2, /** Use the bus clock divided by 2 as the ADC clock source. */
    AltClock,        /** Use an alternative clock source for the ADC. */
    asynClock        /** Use an asynchronous clock source for the ADC. */
} HAL_bus_clock_t;

/**
 * @brief Enumeration for ADC trigger sources.
 *
 */
typedef enum trigger
{
    software_trigger, /** Start ADC conversion with a software trigger. */
    hardware_trigger  /** Start ADC conversion with a hardware trigger. */
} HAL_trigger_select_t;

typedef enum
{
    input_channel,     /** Field for selecting the input channel. */
    differential_mode, /** Field for enabling/disabling differential mode. */
    interrupt_enable   /** Field for enabling/disabling interrupts. */
} HAL_SC1_field;

typedef enum interrupt_conversion
{
    disable_interrupt, /** Disable the conversion complete interrupt. */
    enable_interrupt   /** Enable the conversion complete interrupt. */
} HAL_conversion_complete_interrupt_t;

/**
 * @brief Configures the ADC0 CFG1 register
 *
 * @param mode The ADC conversion mode
 * @param select_clock Select clock source for the ADC
 */
void HAL_ADC0_ConfigRegister1(HAL_ADC_MODE_single_ended_t mode, HAL_bus_clock_t select_clock);

/**
 * @brief Configures the ADC0 SC2 register
 *
 * @param select The trigger source for starting ADC conversion
 */
void HAL_ADC0_StatusAndControl2(HAL_trigger_select_t select);

/**
 * @brief Configure ADC SC1 register and starts a conversion
 *
 * @param channel The ADC input channel to convert
 * @param interruptFlag Enable or disable the conversion complete interrupt
 */
void HAL_ADC0_StatusAndControl1(HAL_input_channel_t channel, HAL_conversion_complete_interrupt_t interruptFlag);

/**
 * @brief Returns the result of the most recent ADC conversion
 *
 * @return uint16_t The digital value from the last ADC conversion
 */
uint16_t HAL_ADC0_dataReturn(void);

/*******************************************************************************
 * Code
 ******************************************************************************/

#endif /** _HAL_ADC_H_  */
