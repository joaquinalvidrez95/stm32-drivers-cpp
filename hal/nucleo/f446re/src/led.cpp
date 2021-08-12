/*
 * led.cpp
 *
 *  Created on: Aug 11, 2021
 *      Author: joaquin
 */

#include "hal/nucleo/f446re/inc/led.h"

namespace hal::nucleo::f446re
{
    Led::Led()
    {
    }

    void Led::init()
    {
        handle_.init();
    }

    void Led::toggle()
    {
        handle_.toggle_pin();
    }
    constexpr mcal::peripherals::gpio::Cfg Led::cfg_;

} // namespace hal::nucleo::f446re
