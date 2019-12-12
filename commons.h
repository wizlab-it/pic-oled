/*
 * 20190312.008
 * OLED 128x32
 *
 * File: commons.h
 * Processor: PIC16F1825
 * Author: wizlab.it
 */

#ifndef COMMONS_H
#define COMMONS_H

#include <xc.h>
#include <stdint.h>
#include "I2CMaster.h"
#include "OLED.h"

#define _XTAL_FREQ 32000000     //CPU Frequency

//External functions
extern void init(void);

#endif