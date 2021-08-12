/*
 * reg.h
 *
 *  Created on: Aug 11, 2021
 *      Author: joaquin
 */

#ifndef PERIPHERALS_SPI_INC_REG_H_
#define PERIPHERALS_SPI_INC_REG_H_

#include <cstdint>

#include "stm32f446xx.h"

namespace mcal
{
    namespace peripherals
    {
        namespace spi
        {
            struct Reg
            {
                struct
                {
                    volatile unsigned int CPHA : 1;
                    volatile unsigned int CPOL : 1;
                    volatile unsigned int MSTR : 1;
                    volatile unsigned int BR : 3;
                    volatile unsigned int SPE : 1;
                    volatile unsigned int LSBFIRST : 1;
                    volatile unsigned int SSI : 1;
                    volatile unsigned int SSM : 1;
                    volatile unsigned int RXONLY : 1;
                    volatile unsigned int DFF : 1;
                    volatile unsigned int CRCNEXT : 1;
                    volatile unsigned int CRCEN : 1;
                    volatile unsigned int BIDIOE : 1;
                    volatile unsigned int BIDIMODE : 1;
                    unsigned int reserved : 16;
                } CR1;
                struct
                {
                    volatile unsigned int RXDMAEN : 1;
                    volatile unsigned int TXDMAEN : 1;
                    volatile unsigned int SSOE : 1;
                    unsigned int reserved_0 : 1;
                    volatile unsigned int FRF : 1;
                    volatile unsigned int ERRIE : 1;
                    volatile unsigned int RXNEIE : 1;
                    volatile unsigned int TXEIE : 1;
                    unsigned int reserved_1 : 24;
                } CR2;

                struct
                {
                    volatile unsigned int RXNE : 1;
                    volatile unsigned int TXE : 1;
                    volatile unsigned int CHSIDE : 1;
                    volatile unsigned int UDR : 1;
                    volatile unsigned int CRCERR : 1;
                    volatile unsigned int MODF : 1;
                    volatile unsigned int OVR : 1;
                    volatile unsigned int BSY : 1;
                    volatile unsigned int FRE : 1;
                    unsigned int reserved : 23;
                } SR;

                volatile uint32_t DR;
                volatile uint32_t CRCPR;
                volatile uint32_t RXCRCR;
                volatile uint32_t TXCRCR;
                volatile uint32_t I2SCFGR;
                volatile uint32_t I2SPR;
            };

#define SPI1 ((Reg *)SPI1_BASEADDR)
#define SPI2 ((Reg *)SPI2_BASEADDR)
#define SPI3 ((Reg *)SPI3_BASEADDR)
#define SPI4 ((Reg *)SPI4_BASEADDR)
        } // namespace spi

    } // namespace peripherals

} // namespace mcal

#endif /* PERIPHERALS_SPI_INC_REG_H_ */
