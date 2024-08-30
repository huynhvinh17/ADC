#ifndef _HAL_SIM_H_
#define _HAL_SIM_H_

#include "MKL46Z4.h"
#include "stdint.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*******************************************************************************
 * Prototype
 ******************************************************************************/

/**
 * @brief Enumeration for system clock control settings for various GPIO port
 *
 */
typedef enum port
{
    PORTA_clockEnable = SIM_SCGC5_PORTA_MASK, /** Bit mask for enabling the clock to PORTA */
    PORTB_clockEnable = SIM_SCGC5_PORTB_MASK, /** Bit mask for enabling the clock to PORTB */
    PORTC_clockEnable = SIM_SCGC5_PORTC_MASK, /** Bit mask for enabling the clock to PORTC */
    PORTD_clockEnable = SIM_SCGC5_PORTD_MASK, /** Bit mask for enabling the clock to PORTD */
    PORTE_clockEnable = SIM_SCGC5_PORTE_MASK  /** Bit mask for enabling the clock to PORTE */
} HAL_port_SCGC5_clock_control_t;

typedef enum SCGC6
{
    FTF_clockEnable = SIM_SCGC6_FTF_MASK,       /** Bit mask for enabling the clock to PORTE */
    DMAMUX_clockEnable = SIM_SCGC6_DMAMUX_MASK, /** Bit mask for enabling the clock to PORTE */
    I2S_clockEnable = SIM_SCGC6_I2S_MASK,       /** Bit mask for enabling the clock to PORTE */
    PIT_clockEnable = SIM_SCGC6_PIT_MASK,       /** Bit mask for enabling the clock to PORTE */
    TPM0_clockEnable = SIM_SCGC6_TPM0_MASK,     /** Bit mask for enabling the clock to PORTE */
    TPM1_clockEnable = SIM_SCGC6_TPM1_MASK,     /** Bit mask for enabling the clock to PORTD */
    TPM2_clockEnable = SIM_SCGC6_TPM2_MASK,     /** Bit mask for enabling the clock to PORTC */
    ADC0_clockEnable = SIM_SCGC6_ADC0_MASK,     /** Bit mask for enabling the clock to PORTA */
    RTC_clockEnable = SIM_SCGC6_RTC_MASK,       /** Bit mask for enabling the clock to PORTB */
    DAC0_clockEnable = SIM_SCGC6_DAC0_MASK      /** Bit mask for enabling the clock to PORTE */

} HAL_SCGC6_clock_control_t;

/**
 * @brief Enable clock for a peripheral port
 *
 * @param portClockEnable The clock enable bit mask for peripheral port
 */
void HAL_SIM_SCGC5_EnableClock(HAL_port_SCGC5_clock_control_t portClockEnable);

void HAL_SIM_SCGC6_EnableClock(HAL_SCGC6_clock_control_t portClockEnable);

/*******************************************************************************
 * Code
 ******************************************************************************/

#endif /** HAL_SIM_H */
