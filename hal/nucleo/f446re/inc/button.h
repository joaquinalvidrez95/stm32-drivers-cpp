/*
 * button.h
 *
 *  Created on: Aug 11, 2021
 *      Author: joaquin
 */

#ifndef NUCLEO_F446RE_INC_BUTTON_H_
#define NUCLEO_F446RE_INC_BUTTON_H_

#include "mcal/peripherals/gpio/inc/handle.h"
#include "mcal/peripherals/gpio/inc/configuration.h"
#include "mcal/peripherals/inc/mechanism.h"

namespace hal::nucleo::f446re
{
    class Button
    {
    public:
        Button();
        void init(mcal::peripherals::Mechanism mechanism =
                      mcal::peripherals::Mechanism::polling);
        void wait_till_pressed();
        bool is_pressed();
        void handle_irq();

    private:
        static constexpr mcal::peripherals::gpio::Cfg cfg_{
            mcal::peripherals::gpio::Cfg::Channel::c,
            mcal::peripherals::gpio::Cfg::Pin_num::p13,
            mcal::peripherals::gpio::Cfg::Mode::in,
            mcal::peripherals::gpio::Cfg::Out_type::push_pull,
            mcal::peripherals::gpio::Cfg::Pull_mode::none,
            mcal::peripherals::gpio::Cfg::Speed::fast,
            mcal::peripherals::gpio::Cfg::Alternate_function::f0,
        };

        static constexpr mcal::peripherals::gpio::Cfg interrupt_cfg_{
            mcal::peripherals::gpio::Cfg::Channel::c,
            mcal::peripherals::gpio::Cfg::Pin_num::p13,
            mcal::peripherals::gpio::Cfg::Mode::falling_transition_interrupt,
            mcal::peripherals::gpio::Cfg::Out_type::push_pull,
            mcal::peripherals::gpio::Cfg::Pull_mode::none,
            mcal::peripherals::gpio::Cfg::Speed::fast,
            mcal::peripherals::gpio::Cfg::Alternate_function::f0,
        };
        mcal::peripherals::gpio::Handle handle_{&cfg_};
    };
} // namespace hal::nucleo::f446re

#endif /* NUCLEO_F446RE_INC_BUTTON_H_ */
