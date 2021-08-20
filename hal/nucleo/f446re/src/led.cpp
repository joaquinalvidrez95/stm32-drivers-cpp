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
        constexpr mcal::peripherals::gpio::Cfg g_cfg{
            mcal::peripherals::gpio::Cfg::Channel::a,
            mcal::peripherals::gpio::Cfg::Pin_num::p5,
            mcal::peripherals::gpio::Cfg::Mode::out,
            mcal::peripherals::gpio::Cfg::Out_type::push_pull,
            mcal::peripherals::gpio::Cfg::Pull_mode::none,
            mcal::peripherals::gpio::Cfg::Speed::fast,
            mcal::peripherals::gpio::Cfg::Alternate_function::f0,
        };
    } // namespace

    Led::Led() : handle_{g_cfg}
    {
    }

    void Led::toggle() const
    {
        handle_.toggle_pin();
    }
} // namespace hal::nucleo::f446re
