/*
 * led.cpp
 *
 *  Created on: Aug 11, 2021
 *      Author: joaquin
 */

#include "hal/nucleo/f446re/inc/led.h"

namespace hal::nucleo::f446re
{
    namespace
    {
        constexpr mcal::peripherals::gpio::cfg g_cfg{
            mcal::peripherals::gpio::channel::a,
            mcal::peripherals::gpio::pin_num::p5,
            mcal::peripherals::gpio::mode::out,
            mcal::peripherals::gpio::out_type::push_pull,
            mcal::peripherals::gpio::pull_mode::none,
            mcal::peripherals::gpio::speed::fast,
            mcal::peripherals::gpio::alternate_function::f0,
        };
    } // namespace

    led::led() : handle_{g_cfg}
    {
    }

    void led::toggle() const
    {
        handle_.toggle_pin();
    }
} // namespace hal::nucleo::f446re
