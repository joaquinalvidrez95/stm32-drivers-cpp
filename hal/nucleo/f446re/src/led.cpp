/*
 * led.cpp
 *
 *  Created on: Aug 11, 2021
 *      Author: joaquin
 */

#include "hal/nucleo/f446re/inc/led.h"

namespace hal
{
    namespace nucleo
    {
        namespace f446re
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
            constexpr mcal::peripherals::gpio::Configuration Led::cfg_;

        } // namespace f446re
    }     // namespace nucleo
} // namespace hal
