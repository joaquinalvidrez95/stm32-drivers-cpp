/*
 * button.cpp
 *
 *  Created on: Aug 11, 2021
 *      Author: joaquin
 */

#include "mcal/peripherals/gpio/inc/handle.h"
#include "utils/inc/utils.h"
#include "hal/nucleo/f446re/inc/button.h"

namespace hal::nucleo::f446re
{
    namespace
    {
        constexpr mcal::peripherals::gpio::Cfg cfg_{
            mcal::peripherals::gpio::Cfg::Channel::c,
            mcal::peripherals::gpio::Cfg::Pin_num::p13,
            mcal::peripherals::gpio::Cfg::Mode::in,
            mcal::peripherals::gpio::Cfg::Out_type::push_pull,
            mcal::peripherals::gpio::Cfg::Pull_mode::none,
            mcal::peripherals::gpio::Cfg::Speed::fast,
            mcal::peripherals::gpio::Cfg::Alternate_function::f0,
        };

        constexpr mcal::peripherals::gpio::Cfg interrupt_cfg_{
            mcal::peripherals::gpio::Cfg::Channel::c,
            mcal::peripherals::gpio::Cfg::Pin_num::p13,
            mcal::peripherals::gpio::Cfg::Mode::falling_transition_interrupt,
            mcal::peripherals::gpio::Cfg::Out_type::push_pull,
            mcal::peripherals::gpio::Cfg::Pull_mode::none,
            mcal::peripherals::gpio::Cfg::Speed::fast,
            mcal::peripherals::gpio::Cfg::Alternate_function::f0,
        };
    } // namespace

    Button::Button(mcal::peripherals::Mechanism mechanism)
        : handle_{mcal::peripherals::Mechanism::polling ==
                          mechanism
                      ? cfg_
                      : interrupt_cfg_}
    {
        if (mcal::peripherals::Mechanism::interrupt == mechanism)
        {
            // TODO: Check if it makes sense to move this to Handle's
            // constructor
            handle_.set_irq_enabled(true);
        }
    }

    void Button::wait_till_pressed() const
    {
        while (!is_pressed())
        {
        }
        utils::delay();
    }

    bool Button::is_pressed() const
    {
        return mcal::peripherals::gpio::Pin_state::reset == handle_.read_pin();
    }

    void Button::handle_irq() const
    {
        handle_.handle_irq();
    }
} // namespace hal::nucleo::f446re
