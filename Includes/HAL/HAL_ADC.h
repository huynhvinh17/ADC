#ifndef _HAL_ADC_H_
#define _HAL_ADC_H_

#include "MKL46Z4.h"
#include "stdbool.h"
#include "stdint.h"

typedef enum input_channel
{
    DADP0_DAD0,
    DADP1_DAD1,
    DADP2_DAD2,
    DADP3_DAD3,
    AD4,
    AD5,
    AD6,
    AD7,
    AD8,
    AD9,
    AD10
} HAL_input_channel_t;

typedef enum mode
{
    convert8Bit,
    convert12Bit,
    convert10Bit,
    convert16Bit,
} HAL_ADC_MODE_single_ended_t;

typedef enum bus_clock
{
    busClock,
    busClockDivide2,
    AltClock,
    asynClock
} HAL_bus_clock_t;

typedef enum trigger
{
    software_trigger,
    hardware_trigger
} HAL_trigger_select_t;

typedef enum
{
    input_channel,
    differential_mode,
    interrupt_enable
} HAL_SC1_field;

typedef enum interrupt_conversion
{
    disable_interrupt,
    enable_interrupt
} HAL_conversion_complete_interrupt_t;

void HAL_ADC0_ConfigRegister1(HAL_ADC_MODE_single_ended_t mode, HAL_bus_clock_t select_clock);

void HAL_ADC0_StatusAndControl2(HAL_trigger_select_t select);

void HAL_ADC0_StatusAndControl1(HAL_input_channel_t channel, HAL_conversion_complete_interrupt_t interruptFlag);

uint16_t HAL_ADC0_dataReturn(void);

#endif /** _HAL_ADC_H_  */
