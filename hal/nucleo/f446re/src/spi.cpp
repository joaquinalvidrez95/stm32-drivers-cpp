/*
 * spi.cpp
 *
 *  Created on: Aug 10, 2021
 *      Author: joaquin
 */

#include "hal/nucleo/f446re/inc/spi.h"

#include "mcal/peripherals/spi/inc/handle.h"
#include "mcal/peripherals/gpio/inc/handle.h"
#include "mcal/peripherals/gpio/inc/configuration.h"

namespace hal::nucleo::f446re
{
    namespace
    {
        // D8
        constexpr mcal::peripherals::gpio::Cfg g_sck_cfg{
            mcal::peripherals::gpio::Cfg::Channel::a,
            mcal::peripherals::gpio::Cfg::Pin_num::p9,
            mcal::peripherals::gpio::Cfg::Mode::alternate_function,
            mcal::peripherals::gpio::Cfg::Out_type::push_pull,
            mcal::peripherals::gpio::Cfg::Pull_mode::none,
            mcal::peripherals::gpio::Cfg::Speed::low,
            mcal::peripherals::gpio::Cfg::Alternate_function::f5,
        };

        // H26
        constexpr mcal::peripherals::gpio::Cfg g_mosi_cfg{
            mcal::peripherals::gpio::Cfg::Channel::b,
            mcal::peripherals::gpio::Cfg::Pin_num::p15,
            mcal::peripherals::gpio::Cfg::Mode::alternate_function,
            mcal::peripherals::gpio::Cfg::Out_type::push_pull,
            mcal::peripherals::gpio::Cfg::Pull_mode::none,
            mcal::peripherals::gpio::Cfg::Speed::low,
            mcal::peripherals::gpio::Cfg::Alternate_function::f5,
        };

        // D5
        constexpr mcal::peripherals::gpio::Cfg g_nss_cfg{
            mcal::peripherals::gpio::Cfg::Channel::b,
            mcal::peripherals::gpio::Cfg::Pin_num::p4,
            mcal::peripherals::gpio::Cfg::Mode::alternate_function,
            mcal::peripherals::gpio::Cfg::Out_type::push_pull,
            mcal::peripherals::gpio::Cfg::Pull_mode::none,
            mcal::peripherals::gpio::Cfg::Speed::low,
            mcal::peripherals::gpio::Cfg::Alternate_function::f7,
        };

        constexpr mcal::peripherals::spi::Cfg cfg{};
    } // namespace

    Spi::Spi()
        : h_sck_{g_sck_cfg},
          h_mosi_{g_mosi_cfg},
          h_nss_{g_nss_cfg},
          handle_{cfg}
    {
    }

    const mcal::peripherals::spi::Handle &Spi::handle() const
    {
        return handle_;
    }
}
