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
 * @brief Main function that initializes peripherals and reads ADC values to control an LED.
 *
 * @return int always returns 0
 */
int main(void)
{
    uint16_t adc_value = 0; /** Variable to store the ADC conversion result */

    Init_LED_Red();   /** Initialize the red LED */
    Init_LED_Green(); /** Initialize the green LED */
    ADC0_Init();      /** Initialize the ADC module */

    /** Read ADC value and adjust the LED configuration */
    while (1)
    {
        ADC0_Read(DADP3_DAD3);         /** Read analog value from ADC channel */
        adc_value = ADC_returnValue(); /** Retrieve the ADC conversion result */
        config_Led_LIGHT(adc_value);   /** Configure LAD based on the ADC value */
    }

    return 0;
}
