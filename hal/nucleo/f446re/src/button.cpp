/*
 * button.cpp
 *
 *  Created on: Aug 11, 2021
 *      Author: joaquin
 */

#include "hal/nucleo/f446re/inc/button.h"

#include "utils/inc/utils.h"
#include "mcal/peripherals/gpio/inc/ext.h"

namespace hal::nucleo::f446re
{
    namespace
    {
        constexpr mcal::peripherals::gpio::cfg cfg_{
            mcal::peripherals::gpio::channel::c,
            mcal::peripherals::gpio::pin_num::p13,
            mcal::peripherals::gpio::mode::in,
            mcal::peripherals::gpio::out_type::push_pull,
            mcal::peripherals::gpio::pull_mode::none,
            mcal::peripherals::gpio::speed::fast,
            mcal::peripherals::gpio::alternate_function::f0,
        };

        constexpr mcal::peripherals::gpio::cfg interrupt_cfg_{
            mcal::peripherals::gpio::channel::c,
            mcal::peripherals::gpio::pin_num::p13,
            mcal::peripherals::gpio::mode::falling_transition_interrupt,
            mcal::peripherals::gpio::out_type::push_pull,
            mcal::peripherals::gpio::pull_mode::none,
            mcal::peripherals::gpio::speed::fast,
            mcal::peripherals::gpio::alternate_function::f0,
        };
    } // namespace

    button::button(mcal::peripherals::mechanism mechanism)
        : handle_{mcal::peripherals::mechanism::polling ==
                          mechanism
                      ? cfg_
                      : interrupt_cfg_}
    {
        if (mcal::peripherals::mechanism::interrupt == mechanism)
        {
            // TODO: Check if it makes sense to move this to handle's
            // constructor
            handle_.set_irq_enabled(true);
        }
    }

    void button::wait_till_pressed() const
    {
        while (!is_pressed())
        {
        }
        utils::delay();
    }

    bool button::is_pressed() const
    {
        return mcal::peripherals::gpio::pin_state::reset == handle_.read_pin();
    }

    void button::handle_irq() const
    {
        handle_.handle_irq();
    }
} // namespace hal::nucleo::f446re
