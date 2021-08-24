/*
 * spi.h
 *
 *  Created on: Aug 10, 2021
 *      Author: joaquin
 */

#ifndef NUCLEO_F446RE_INC_SPI_H_
#define NUCLEO_F446RE_INC_SPI_H_

#include <cstddef>

#include "mcal/peripherals/spi/inc/ext.h"
#include "mcal/peripherals/gpio/inc/ext.h"

namespace hal::nucleo::f446re
{
    class spi
    {
    public:
        spi();

        const mcal::peripherals::spi::handle &handle() const;

    private:
        const mcal::peripherals::gpio::handle h_sck_;
        const mcal::peripherals::gpio::handle h_mosi_;
        const mcal::peripherals::gpio::handle h_nss_;
        const mcal::peripherals::spi::handle handle_;
    };
} // namespace hal::nucleo::f446re

#endif /* NUCLEO_F446RE_INC_SPI_H_ */
