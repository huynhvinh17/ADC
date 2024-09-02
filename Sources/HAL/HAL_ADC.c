#include "../Includes/HAL/HAL_ADC.h"

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
 * @brief Configures the ADC0 CFG1 register
 *
 * @param mode The ADC conversion mode
 * @param select_clock Select clock source for the ADC
 */
void HAL_ADC0_ConfigRegister1(HAL_ADC_MODE_single_ended_t mode, HAL_bus_clock_t select_clock)
{
    ADC0->CFG1 = ADC_CFG1_MODE(mode) | ADC_CFG1_ADICLK(select_clock);
}

/**
 * @brief Configures the ADC0 SC2 register
 *
 * @param select The trigger source for starting ADC conversion
 */
void HAL_ADC0_StatusAndControl2(HAL_trigger_select_t select)
{
    ADC0->SC2 = ADC_SC2_ADTRG(select);
}

/**
 * @brief Configure ADC SC1 register and starts a conversion
 *
 * @param channel The ADC input channel to convert
 * @param interruptFlag Enable or disable the conversion complete interrupt
 */
void HAL_ADC0_StatusAndControl1(HAL_input_channel_t channel, HAL_conversion_complete_interrupt_t interruptFlag)
{
    ADC0->SC1[0] = ADC_SC1_ADCH(channel);
    ADC0->SC1[0] |= ADC_SC1_AIEN(enable_interrupt);
    while (!(ADC0->SC1[0] & ADC_SC1_COCO(1)))
    {
    };
}

/**
 * @brief Returns the result of the most recent ADC conversion
 *
 * @return uint16_t The digital value from the last ADC conversion
 */
uint16_t HAL_ADC0_dataReturn(void)
{
    return ADC0->R[0];
}
