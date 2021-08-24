/*
 * spi.cpp
 *
 *  Created on: Aug 10, 2021
 *      Author: joaquin
 */

#include "hal/nucleo/f446re/inc/spi.h"

#include "mcal/peripherals/spi/inc/ext.h"
#include "mcal/peripherals/gpio/inc/ext.h"

namespace hal::nucleo::f446re
{
    namespace
    {
        // D8
        constexpr mcal::peripherals::gpio::cfg g_sck_cfg{
            mcal::peripherals::gpio::channel::a,
            mcal::peripherals::gpio::pin_num::p9,
            mcal::peripherals::gpio::mode::alternate_function,
            mcal::peripherals::gpio::out_type::push_pull,
            mcal::peripherals::gpio::pull_mode::none,
            mcal::peripherals::gpio::speed::low,
            mcal::peripherals::gpio::alternate_function::f5,
        };

        // H26
        constexpr mcal::peripherals::gpio::cfg g_mosi_cfg{
            mcal::peripherals::gpio::channel::b,
            mcal::peripherals::gpio::pin_num::p15,
            mcal::peripherals::gpio::mode::alternate_function,
            mcal::peripherals::gpio::out_type::push_pull,
            mcal::peripherals::gpio::pull_mode::none,
            mcal::peripherals::gpio::speed::low,
            mcal::peripherals::gpio::alternate_function::f5,
        };

        // D5
        constexpr mcal::peripherals::gpio::cfg g_nss_cfg{
            mcal::peripherals::gpio::channel::b,
            mcal::peripherals::gpio::pin_num::p4,
            mcal::peripherals::gpio::mode::alternate_function,
            mcal::peripherals::gpio::out_type::push_pull,
            mcal::peripherals::gpio::pull_mode::none,
            mcal::peripherals::gpio::speed::low,
            mcal::peripherals::gpio::alternate_function::f7,
        };

        constexpr mcal::peripherals::spi::cfg cfg{};
    } // namespace

    spi::spi()
        : h_sck_{g_sck_cfg},
          h_mosi_{g_mosi_cfg},
          h_nss_{g_nss_cfg},
          handle_{cfg}
    {
    }

    const mcal::peripherals::spi::handle &spi::handle() const
    {
        return handle_;
    }
}
