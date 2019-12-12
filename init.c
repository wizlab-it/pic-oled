/*
 * 20190312.006
 * OLED 128x32
 *
 * File: init.c
 * Processor: PIC16F1825
 * Author: wizlab.it
 */

#include "init.h"


/*==============================================================================
 * System initialization
 *============================================================================*/
void init(void) {
    /*
    * Init Oscillator: 32MHz
    *  - SPLLEN[7]: 1 (4x PLL enabled)
    *  - IRCF[6-3]: 1110 (8MHz/32MHz)
    *  - SCS[1-0]: 00 (Clock by FOSC [FOSC = INTOSC])
    */
    OSCCON = 0b11110000;
    OSCTUNE = 0x00;

    /*
    * Options Register
    * Timer0 initialized here
    *  - WPUEN[7]: 1 (Weak pull ups disabled)
    *  - INTEDG[6]: 1 (External INT PIN interrupt on rising edge)
    *  - TMR0CS[5]: 0 (Timer0 source clock from internal instruction cycle clock [FOSC/4])
    *  - TMR0SE[4]: 1 (Timer0 increment on high-to-low transaction on INT PIN)
    *  - PSA[3]: 0 (Prescaler assigned to Timer0)
    *  - PS[2-0]: 111 (Prescaler set to 256)
    */
    OPTION_REG = 0b11010111;

    /*
    * PORT A
    *  - RA[7-6]: 00 (Not implemented)
    *  - RA[5]: 0 (Output, I2C RXTX led)
    *  - RA[4-0]: 1 (Input, Unused)
    */
    TRISA = 0b00011111;
    ANSELA = 0b00000000;
    LATA = 0;

    /*
    * PORT C
    *  - RC[7-6]: 00 (Not implemented)
    *  - RC[5-2]: 1 (Input, Unused)
    *  - RC[1]: 1 (Input, I2C Data [SDA])
    *  - RC[0]: 1 (Input, I2C Clock [SCK])
    */
    TRISC = 0b00111111;
    ANSELC = 0b00000000;
    LATC = 0;

    /*
    * Initialize I2C bus
    */
    I2C_Master_Init(400000);

    /*
    * Interrupts
    * TMR0IE: 0 (Timer0 interrupt disabled)
    * SSP1 (I2C): 0 (SSP1 interrupt initially disabled)
    * PEIE: 1 (Peripheral interrupts disabled)
    * GIE: 1 (Global interrupts disabled)
    */
    TMR0IE = 0;
    SSP1IE = 0;
    PEIE = 0;
    GIE = 0;
}


/*==============================================================================
 * Interrupt Service Routine
 *============================================================================*/
void __interrupt() isr(void) {
}