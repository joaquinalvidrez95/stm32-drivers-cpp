/*
 * nucleof446re.h
 *
 *  Created on: Nov 22, 2020
 *      Author: joaquin.alvidrez
 */

#ifndef NUCLEOF446RE_H_
#define NUCLEOF446RE_H_

#include "drivers/peripherals/gpio/inc/gpio.h"
#include "drivers/peripherals/inc/mechanism.h"

#ifdef __cplusplus
extern "C"
{
#endif

	namespace nucleo
	{
		class F446re
		{
		public:
			void init_button(drivers::peripherals::Mechanism mechanism = drivers::peripherals::Mechanism::polling);
			void wait_till_button_pressed();
			bool is_button_pressed();
			void init_led();
			void toggle_led();
			void handle_irq_button();
			void set_button_irq_enabled(bool b_enabled);

		private:
			static constexpr drivers::peripherals::gpio::Configuration button_cfg{
				drivers::peripherals::gpio::Configuration::Channel::c,
				drivers::peripherals::gpio::Configuration::Pin_num::thirteen,
				drivers::peripherals::gpio::Configuration::Mode::in,
				drivers::peripherals::gpio::Configuration::Out_type::push_pull,
				drivers::peripherals::gpio::Configuration::Pull_mode::none,
				drivers::peripherals::gpio::Configuration::Speed::fast,
				drivers::peripherals::gpio::Configuration::Alternate_function::zero,
			};
			static constexpr drivers::peripherals::gpio::Configuration led_cfg{
				drivers::peripherals::gpio::Configuration::Channel::a,
				drivers::peripherals::gpio::Configuration::Pin_num::five,
				drivers::peripherals::gpio::Configuration::Mode::out,
				drivers::peripherals::gpio::Configuration::Out_type::push_pull,
				drivers::peripherals::gpio::Configuration::Pull_mode::none,
				drivers::peripherals::gpio::Configuration::Speed::fast,
				drivers::peripherals::gpio::Configuration::Alternate_function::zero,
			};
			static constexpr drivers::peripherals::gpio::Configuration interrupt_button_cfg{
				drivers::peripherals::gpio::Configuration::Channel::c,
				drivers::peripherals::gpio::Configuration::Pin_num::thirteen,
				drivers::peripherals::gpio::Configuration::Mode::falling_transition_interrupt,
				drivers::peripherals::gpio::Configuration::Out_type::push_pull,
				drivers::peripherals::gpio::Configuration::Pull_mode::none,
				drivers::peripherals::gpio::Configuration::Speed::fast,
				drivers::peripherals::gpio::Configuration::Alternate_function::zero,
			};
			drivers::peripherals::gpio::Handle h_button_{&button_cfg};
			drivers::peripherals::gpio::Handle h_led_{&led_cfg};
		};
	} // namespace nucleo

#ifdef __cplusplus
}
#endif
#endif /* NUCLEOF446RE_H_ */
