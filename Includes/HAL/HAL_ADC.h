#ifndef _HAL_ADC_H_
#define _HAL_ADC_H_

#include "MKL46Z4.h"

typedef enum
{
    convert8Bit,
    convert12Bit,
    convert10Bit,
    convert16Bit,
} HAL_ADC_MODE_single_ended_t;

typedef enum
{
    busClock,
    busClockDivide2,
    AltClock,
    asynClock
} bus_clock_t;

typedef enum
{
    software_trigger,
    hardware_trigger
} trigger_select_t;

typedef enum
{
    input_channel,
    differential_mode,
    interrupt_enable
} SC1_field;

void HAL_ADC0_CFG1(HAL_ADC_MODE_single_ended_t mode, bus_clock_t select_clock);

void HAL_ADC0_SC2(trigger_select_t select);

void HAL_ADC0_SC1(SC1_field field, uint8_t channel);

uint32_t HAL_ADC0_dataReturn();

void HAL_ADC0_Interrtup_Enable();

float ADC_to_Percentage(uint16_t adc_value);

uint16_t HAL_ADC0_flagConversion();

#endif /** _HAL_ADC_H_  */
