/* Copyright 2016, Eric Pernia
 * All rights reserved.
 *
 * This file is part sAPI library for microcontrollers.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

// Date:
// 2016-11-20 Eric Pernia - Software I2C

#ifndef _SAPI_SOFTWARE_I2C_H_
#define _SAPI_SOFTWARE_I2C_H_

/*==================[inclusions]=============================================*/

#include "sapi_datatypes.h"
#include "sapi_peripheral_map.h"

/*==================[c++]====================================================*/
#ifdef __cplusplus
extern "C" {
#endif

/*==================[macros]=================================================*/

#define I2C_SOFTWARE_SDA_DIR   GPIO7
#define I2C_SOFTWARE_SDA_IN    GPIO7
#define I2C_SOFTWARE_SDA_OUT   GPIO7

#define I2C_SOFTWARE_SCL_DIR   GPIO8
#define I2C_SOFTWARE_SCL_IN    GPIO8
#define I2C_SOFTWARE_SCL_OUT   GPIO8

#define SOFTWARE_I2C_DEBUG     0

/*==================[typedef]================================================*/

typedef enum {
   I2C_SOFTWARE_WRITE = 0,
   I2C_SOFTWARE_READ  = 1
} I2C_Software_rw_t;

typedef enum {
   I2C_SOFTWARE_NACK = 0,
   I2C_SOFTWARE_ACK  = 1
} I2C_Software_ack_t;

/*==================[external functions declaration]=========================*/

bool_t i2cSoftwareInit( i2cMap_t i2cNumber, uint32_t clockRateHz );

bool_t i2cSoftwareRead( i2cMap_t  i2cNumber,
                        uint8_t  i2cSlaveAddress,
                        uint8_t* receiveDataBuffer,
                        uint16_t receiveDataBufferSize,
                        bool_t   sendReadStop );

bool_t i2cSoftwareWrite( i2cMap_t  i2cNumber,
                         uint8_t  i2cSlaveAddress,
                         uint8_t* transmitDataBuffer,
                         uint16_t transmitDataBufferSize,
                         bool_t   sendWriteStop );

bool_t i2cSoftwareWriteRead( i2cMap_t  i2cNumber,
                             uint8_t  i2cSlaveAddress,
                             uint8_t* dataToReadBuffer,
                             uint16_t dataToReadBufferSize,
                             bool_t   sendWriteStop,
                             uint8_t* receiveDataBuffer,
                             uint16_t receiveDataBufferSize,
                             bool_t   sendReadStop );

// Software Master I2C --------------------------------------------------------

void i2cSoftwareDelay( tick_t duration );

void i2cSoftwareMasterWriteStart( void );

void i2cSoftwareMasterWriteStop( void );

bool_t i2cSoftwareMasterWriteAddress( uint8_t i2cSlaveAddress,
                                      I2C_Software_rw_t readOrWrite );

bool_t i2cSoftwareMasterWriteByte( uint8_t dataByte );

uint8_t i2cSoftwareMasterReadByte( bool_t ack );

#if( SOFTWARE_I2C_DEBUG == 1 )
void i2cSoftwareMasterPinTestInit( void );
void i2cSoftwareMasterPinTest( void );
#endif

/*==================[ISR external functions declaration]=====================*/

/*==================[c++]====================================================*/
#ifdef __cplusplus
}
#endif

/*==================[end of file]============================================*/
#endif /* _SAPI_SOFTWARE_I2C_H_ */