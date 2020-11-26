/*
 * nucleof446re.h
 *
 *  Created on: Nov 22, 2020
 *      Author: joaquin.alvidrez
 */

#ifndef NUCLEOF446RE_H_
#define NUCLEOF446RE_H_

#include <stdint.h>

#include "drivers/peripherals/gpio/inc/gpio.h"

namespace nucleo
{
	// enum class Button_state : uint32_t
	// {
	// 	not_pressed,
	// 	pressed,
	// };
	class F446re
	{
	public:
		void init_button();
		void wait_till_button_pressed();
		bool is_button_pressed();
		void init_led();
		void toggle_led();

	private:
		drivers::peripherals::gpio::Configuration m_button_cfg{
			drivers::peripherals::gpio::Configuration::Channel::c,
			drivers::peripherals::gpio::Configuration::Pin_num::thirteen,
			drivers::peripherals::gpio::Configuration::Mode::in,
			drivers::peripherals::gpio::Configuration::Out_type::push_pull,
			drivers::peripherals::gpio::Configuration::Pull_mode::none,
			drivers::peripherals::gpio::Configuration::Speed::fast,
			drivers::peripherals::gpio::Configuration::Alternate_function::zero,
		};
		drivers::peripherals::gpio::Handle mh_button{m_button_cfg};
		drivers::peripherals::gpio::Configuration m_led_cfg{
			drivers::peripherals::gpio::Configuration::Channel::a,
			drivers::peripherals::gpio::Configuration::Pin_num::five,
			drivers::peripherals::gpio::Configuration::Mode::out,
			drivers::peripherals::gpio::Configuration::Out_type::push_pull,
			drivers::peripherals::gpio::Configuration::Pull_mode::none,
			drivers::peripherals::gpio::Configuration::Speed::fast,
			drivers::peripherals::gpio::Configuration::Alternate_function::zero,
		};
		drivers::peripherals::gpio::Handle mh_led{m_led_cfg};
	};
} // namespace nucleo



#endif /* NUCLEOF446RE_H_ */
