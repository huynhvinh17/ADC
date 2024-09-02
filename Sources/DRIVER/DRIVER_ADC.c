#include "../Includes/DRIVER/DRIVER_ADC.h"

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
 * @brief Converts the raw ADC value to a percentage.
 *
 * @param adc_value The 16bit ADC value to be converted.
 * @return float The converted percentage value
 */
float ADC_to_Percentage(uint16_t adc_value)
{
    return (adc_value * 100.0) / 65535.0;
}

/**
 * @brief onfigures the ADC0 register 1 with mode and clock settings.
 *
 * @param mode The ADC conversion mode
 * @param select_clock The clock source for the ADC
 */
void DRIVER_ADC0_ConfigRegister1(DRIVER_ADC_MODE_single_ended_t mode, DRIVER_bus_clock_t select_clock)
{
    HAL_ADC0_ConfigRegister1(mode, select_clock);
}

/**
 * @brief Configures the ADC0 and control register 2
 *
 * @param select The trigger source selection
 */
void DRIVER_ADC0_StatusAndControl2(DRIVER_trigger_select_t select)
{
    HAL_ADC0_StatusAndControl2(select);
}

/**
 * @brief Configures the ADC0 and control register 1 and starts a conversion
 *
 * @param channel The ADC input channel to start the conversion on.
 * @param interruptFlag Flag to enable or disable the conversion complete interrupt.
 */
void DRIVER_ADC0_StatusAndControl1(DRIVER_input_channel_t channel, DRIVER_conversion_complete_interrupt_t interruptFlag)
{
    HAL_ADC0_StatusAndControl1(channel, interruptFlag);
}

/**
 * @brief Returns the result of the last ADC conversion.
 *
 * @return uint16_t The ADC conversion result
 */
uint16_t DRIVER_ADC0_dataReturn(void)
{
    return HAL_ADC0_dataReturn();
}
