/*
 * spi.cpp
 *
 *  Created on: Aug 10, 2021
 *      Author: joaquin
 */

#include "hal/nucleo/f446re/inc/spi.h"

namespace hal::nucleo::f446re
{
    namespace
    {
        constexpr mcal::peripherals::spi::Cfg cfg{};

    } // namespace

    Spi::Spi() : handle_{cfg}
    {
    }

    void Spi::init()
    {
    }

    const mcal::peripherals::spi::Handle &Spi::handle() const
    {
        return handle_;
    }
}
