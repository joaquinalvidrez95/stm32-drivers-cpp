/*
 * spi.h
 *
 *  Created on: Aug 10, 2021
 *      Author: joaquin
 */

#ifndef NUCLEO_F446RE_INC_SPI_H_
#define NUCLEO_F446RE_INC_SPI_H_

#include <cstddef>

#include "mcal/peripherals/spi/inc/handle.h"
#include "mcal/peripherals/gpio/inc/handle.h"

namespace hal::nucleo::f446re
{
    class Spi
    {
    public:
        Spi();

        const mcal::peripherals::spi::Handle &handle() const;

    private:
        const mcal::peripherals::gpio::Handle h_sck_;
        const mcal::peripherals::gpio::Handle h_mosi_;
        const mcal::peripherals::gpio::Handle h_nss_;
        const mcal::peripherals::spi::Handle handle_;
    };
} // namespace hal::nucleo::f446re

#endif /* NUCLEO_F446RE_INC_SPI_H_ */
