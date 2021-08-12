/*
 * led.h
 *
 *  Created on: Aug 11, 2021
 *      Author: joaquin
 */

#ifndef NUCLEO_F446RE_INC_LED_H_
#define NUCLEO_F446RE_INC_LED_H_

#include "mcal/peripherals/gpio/inc/handle.h"
#include "mcal/peripherals/gpio/inc/configuration.h"

namespace hal
{
    namespace nucleo
    {
        namespace f446re
        {
            class Led
            {
            public:
                Led();
                void init();
                void toggle();

            private:
                static constexpr mcal::peripherals::gpio::Cfg cfg_{
                    mcal::peripherals::gpio::Cfg::Channel::a,
                    mcal::peripherals::gpio::Cfg::Pin_num::five,
                    mcal::peripherals::gpio::Cfg::Mode::out,
                    mcal::peripherals::gpio::Cfg::Out_type::push_pull,
                    mcal::peripherals::gpio::Cfg::Pull_mode::none,
                    mcal::peripherals::gpio::Cfg::Speed::fast,
                    mcal::peripherals::gpio::Cfg::Alternate_function::zero,
                };
                mcal::peripherals::gpio::Handle handle_{&cfg_};
            };
        } // namespace f446re
    } // namespace nucleo
} // namespace hal

#endif /* NUCLEO_F446RE_INC_LED_H_ */
