#ifndef _DRIVER_ADC_H_
#define _DRIVER_ADC_H_

#include "../Includes/HAL/HAL_ADC.h"
#include "MKL46Z4.h"
#include "stdbool.h"
#include "stdint.h"

float ADC_to_Percentage(uint16_t adc_value);
typedef HAL_input_channel_t DRIVER_input_channel_t;
typedef HAL_ADC_MODE_single_ended_t DRIVER_ADC_MODE_single_ended_t;
typedef HAL_bus_clock_t DRIVER_bus_clock_t;
typedef HAL_trigger_select_t DRIVER_trigger_select_t;
typedef HAL_SC1_field DRIVER_SC1_field;
typedef HAL_conversion_complete_interrupt_t DRIVER_conversion_complete_interrupt_t;

void DRIVER_ADC0_ConfigRegister1(DRIVER_ADC_MODE_single_ended_t mode, DRIVER_bus_clock_t select_clock);

void DRIVER_ADC0_StatusAndControl2(DRIVER_trigger_select_t select);

void DRIVER_ADC0_StatusAndControl1(DRIVER_input_channel_t channel, DRIVER_conversion_complete_interrupt_t interruptFlag);

uint16_t DRIVER_ADC0_dataReturn(void);


#endif /** _DRIVER_ADC_H_  */
