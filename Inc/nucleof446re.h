/*
 * nucleof446re.h
 *
 *  Created on: Nov 22, 2020
 *      Author: joaquin.alvidrez
 */

#ifndef NUCLEOF446RE_H_
#define NUCLEOF446RE_H_

#include "mcal/peripherals/gpio/inc/gpio.h"
#include "mcal/peripherals/inc/mechanism.h"

#ifdef __cplusplus
extern "C"
{
#endif

	namespace nucleo
	{
		class F446re
		{
		public:
			void init_button(mcal::peripherals::Mechanism mechanism = mcal::peripherals::Mechanism::polling);
			void wait_till_button_pressed();
			bool is_button_pressed();
			void init_led();
			void toggle_led();
			void handle_irq_button();
			void set_button_irq_enabled(bool b_enabled);

		private:
			static constexpr mcal::peripherals::gpio::Configuration button_cfg{
				mcal::peripherals::gpio::Configuration::Channel::c,
				mcal::peripherals::gpio::Configuration::Pin_num::thirteen,
				mcal::peripherals::gpio::Configuration::Mode::in,
				mcal::peripherals::gpio::Configuration::Out_type::push_pull,
				mcal::peripherals::gpio::Configuration::Pull_mode::none,
				mcal::peripherals::gpio::Configuration::Speed::fast,
				mcal::peripherals::gpio::Configuration::Alternate_function::zero,
			};
			static constexpr mcal::peripherals::gpio::Configuration led_cfg{
				mcal::peripherals::gpio::Configuration::Channel::a,
				mcal::peripherals::gpio::Configuration::Pin_num::five,
				mcal::peripherals::gpio::Configuration::Mode::out,
				mcal::peripherals::gpio::Configuration::Out_type::push_pull,
				mcal::peripherals::gpio::Configuration::Pull_mode::none,
				mcal::peripherals::gpio::Configuration::Speed::fast,
				mcal::peripherals::gpio::Configuration::Alternate_function::zero,
			};
			static constexpr mcal::peripherals::gpio::Configuration interrupt_button_cfg{
				mcal::peripherals::gpio::Configuration::Channel::c,
				mcal::peripherals::gpio::Configuration::Pin_num::thirteen,
				mcal::peripherals::gpio::Configuration::Mode::falling_transition_interrupt,
				mcal::peripherals::gpio::Configuration::Out_type::push_pull,
				mcal::peripherals::gpio::Configuration::Pull_mode::none,
				mcal::peripherals::gpio::Configuration::Speed::fast,
				mcal::peripherals::gpio::Configuration::Alternate_function::zero,
			};
			mcal::peripherals::gpio::Handle h_button_{&button_cfg};
			mcal::peripherals::gpio::Handle h_led_{&led_cfg};
		};
	} // namespace nucleo

#ifdef __cplusplus
}
#endif
#endif /* NUCLEOF446RE_H_ */
