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

namespace hal
{
    namespace nucleo
    {
        namespace f446re
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
                void set_irq_enabled(bool b_enabled);

            private:
                static constexpr mcal::peripherals::gpio::Configuration cfg_{
                    mcal::peripherals::gpio::Configuration::Channel::c,
                    mcal::peripherals::gpio::Configuration::Pin_num::thirteen,
                    mcal::peripherals::gpio::Configuration::Mode::in,
                    mcal::peripherals::gpio::Configuration::Out_type::push_pull,
                    mcal::peripherals::gpio::Configuration::Pull_mode::none,
                    mcal::peripherals::gpio::Configuration::Speed::fast,
                    mcal::peripherals::gpio::Configuration::Alternate_function::zero,
                };

                static constexpr mcal::peripherals::gpio::Configuration interrupt_cfg_{
                    mcal::peripherals::gpio::Configuration::Channel::c,
                    mcal::peripherals::gpio::Configuration::Pin_num::thirteen,
                    mcal::peripherals::gpio::Configuration::Mode::falling_transition_interrupt,
                    mcal::peripherals::gpio::Configuration::Out_type::push_pull,
                    mcal::peripherals::gpio::Configuration::Pull_mode::none,
                    mcal::peripherals::gpio::Configuration::Speed::fast,
                    mcal::peripherals::gpio::Configuration::Alternate_function::zero,
                };
                mcal::peripherals::gpio::Handle handle_{&cfg_};
            };
        } // namespace f446re
    }     // namespace nucleo
} // namespace hal

#endif /* NUCLEO_F446RE_INC_BUTTON_H_ */
