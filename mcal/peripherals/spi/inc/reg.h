/*
 * reg.h
 *
 *  Created on: Aug 11, 2021
 *      Author: joaquin
 */

#ifndef PERIPHERALS_SPI_INC_REG_H_
#define PERIPHERALS_SPI_INC_REG_H_

#include <cstdint>

namespace mcal::peripherals::spi
{
    struct reg
    {
        volatile uint32_t cr1;
        volatile uint32_t cr2;
        volatile uint32_t sr;

#if 0
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
#endif

        volatile uint32_t dr;
        volatile uint32_t crcpr;
        volatile uint32_t rxcrcr;
        volatile uint32_t txcrcr;
        volatile uint32_t i2scfgR;
        volatile uint32_t i2spr;
    };

    namespace bitfield
    {
        enum class cr1 : uint32_t
        {
            cpha,
            cpol,
            mstr,
            br0,
            br1,
            br2,
            spe,
            lsbfirst,
            ssi,
            ssm,
            rxonly,
            dff,
            crcnext,
            crcen,
            bidioe,
            bidimode,
        };

        enum class cr2 : uint32_t
        {
            rxdmaen,
            txdmaen,
            ssoe,
            _reserved,
            frf,
            errie,
            rxneie,
            txeie,
        };

        enum class sr : uint32_t
        {
            rxne,
            txe,
            chside,
            udr,
            crcerr,
            modf,
            ovr,
            bsy,
            fre,
        };

    } // namespace bitfield

} // namespace mcal::peripherals::spi

#endif /* PERIPHERALS_SPI_INC_REG_H_ */
