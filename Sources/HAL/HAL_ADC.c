#include "../Includes/HAL/HAL_ADC.h"

void HAL_ADC0_ConfigRegister1(HAL_ADC_MODE_single_ended_t mode, HAL_bus_clock_t select_clock)
{
    ADC0->CFG1 = ADC_CFG1_MODE(mode) | ADC_CFG1_ADICLK(select_clock);
}

void HAL_ADC0_StatusAndControl2(HAL_trigger_select_t select)
{
    ADC0->SC2 = ADC_SC2_ADTRG(select);
}

void HAL_ADC0_StatusAndControl1(HAL_input_channel_t channel, HAL_conversion_complete_interrupt_t interruptFlag)
{
    ADC0->SC1[0] = ADC_SC1_ADCH(channel);
    ADC0->SC1[0] |= ADC_SC1_AIEN(enable_interrupt);
    while (!(ADC0->SC1[0] & ADC_SC1_COCO(1)))
    {
    };
}

uint16_t HAL_ADC0_dataReturn(void)
{
    return ADC0->R[0];
}
