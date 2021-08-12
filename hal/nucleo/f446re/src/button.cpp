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
                if (mcal::peripherals::Mechanism::polling == mechanism)
                {
                    handle_.init();
                }
                else
                {
                    handle_.init(&interrupt_cfg_);
                    handle_.set_irq_enabled(true);
                }
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

            constexpr mcal::peripherals::gpio::Cfg Button::cfg_;
            constexpr mcal::peripherals::gpio::Cfg Button::interrupt_cfg_;
        } // namespace f446re
    }     // namespace nucleo
} // namespace hal
