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

int main(void)
{
    uint16_t adc_value = 0;

    Init_LED_Red();
    Init_LED_Green();
    ADC0_Init();

    while (1)
    {
        ADC0_Read(DADP3_DAD3);

        adc_value = ADC_returnValue();

        config_Led_LIGHT(adc_value);
    }

    return 0;
}
