/*
 * 20190312.006
 * OLED 128x32
 *
 * File: I2CMaster.h
 * Processor: PIC16F1825
 * Author: wizlab.it
 */

#ifndef I2CMASTER_H
#define	I2CMASTER_H

#include "commons.h"

#define I2C_MODE_WRITE 0x00
#define I2C_MODE_READ 0x01

void I2C_Master_Init(const uint32_t c);
void I2C_Master_Wait(void);
void I2C_Master_Start(void);
void I2C_Master_RepeatedStart(void);
void I2C_Master_Stop(void);
void I2C_Master_Address(uint8_t address, uint8_t mode);
void I2C_Master_Write(uint8_t d);
uint8_t I2C_Master_Read(uint8_t a);

#endif