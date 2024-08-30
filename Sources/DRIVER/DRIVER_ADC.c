#include "../Includes/DRIVER/DRIVER_ADC.h"

float ADC_to_Percentage(uint16_t adc_value)
{
    return (adc_value * 100.0) / 65535.0;
}

void DRIVER_ADC0_ConfigRegister1(DRIVER_ADC_MODE_single_ended_t mode, DRIVER_bus_clock_t select_clock)
{
    HAL_ADC0_ConfigRegister1(mode, select_clock);
}

void DRIVER_ADC0_StatusAndControl2(DRIVER_trigger_select_t select)
{
    HAL_ADC0_StatusAndControl2(select);
}

void DRIVER_ADC0_StatusAndControl1(DRIVER_input_channel_t channel, DRIVER_conversion_complete_interrupt_t interruptFlag)
{
    HAL_ADC0_StatusAndControl1(channel, interruptFlag);
}

uint16_t DRIVER_ADC0_dataReturn(void)
{
    return HAL_ADC0_dataReturn();
}
