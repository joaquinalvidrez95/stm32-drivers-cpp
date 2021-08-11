/*
 * button.cpp
 *
 *  Created on: Aug 11, 2021
 *      Author: joaquin
 */

#include "mcal/peripherals/gpio/inc/handle.h"
#include "utils.h"
#include "hal/nucleo/f446re/inc/button.h"

namespace hal
{
    namespace nucleo
    {
        namespace f446re
        {
            Button::Button()
            {
            }

            void Button::init(mcal::peripherals::Mechanism mechanism)
            {
                handle_.init((mcal::peripherals::Mechanism::interrupt ==
                              mechanism)
                                 ? &interrupt_cfg_
                                 : nullptr);
            }

            void Button::wait_till_pressed()
            {
                while (!is_pressed())
                {
                }
                utils::delay();
            }

            bool Button::is_pressed()
            {
                return mcal::peripherals::gpio::Pin_state::reset ==
                       handle_.read_pin();
            }

            void Button::handle_irq()
            {
                handle_.handle_irq();
            }

            void Button::set_irq_enabled(bool b_enabled)
            {
                handle_.set_irq_enabled(b_enabled);
            }

            constexpr mcal::peripherals::gpio::Configuration Button::cfg_;
            constexpr mcal::peripherals::gpio::Configuration Button::interrupt_cfg_;
        } // namespace f446re
    }     // namespace nucleo
} // namespace hal
