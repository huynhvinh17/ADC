#include "../Includes/HAL/HAL_ADC.h"

void HAL_ADC0_CFG1(HAL_ADC_MODE_single_ended_t mode, bus_clock_t select_clock)
{
    ADC0->CFG1 = ADC_CFG1_MODE(mode) | ADC_CFG1_ADICLK(select_clock);
}

void HAL_ADC0_SC2(trigger_select_t select)
{
    ADC0->SC2 = ADC_SC2_ADTRG(select);
}

void HAL_ADC0_SC1(SC1_field field, uint8_t channel)
{
    ADC0->SC1[field] = ADC_SC1_ADCH(channel);
    ADC0->SC1[field] |= ADC_SC1_AIEN_MASK;
}

uint32_t HAL_ADC0_dataReturn()
{
    return ADC0->R[0];
}

