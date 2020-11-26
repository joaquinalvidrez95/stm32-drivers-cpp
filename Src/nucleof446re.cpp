/*
 * nucleof446re.cpp
 *
 *  Created on: Nov 22, 2020
 *      Author: joaquin.alvidrez
 */

#include <nucleof446re.h>

#include "drivers/peripherals/gpio/inc/gpio.h"
#include "utils.h"

namespace nucleo
{
	void F446re::init_button()
	{
		mh_button.init();
	}

	void F446re::wait_till_button_pressed()
	{
		while (!is_button_pressed())
		{
		}
		Utils::delay();
	}

	bool F446re::is_button_pressed()
	{
		return drivers::peripherals::gpio::Pin_state::reset == mh_button.read_pin();
	}

	void F446re::init_led()
	{
		mh_led.init();
	}

	void F446re::toggle_led()
	{
		mh_led.toggle_pin();
	}

	const drivers::peripherals::gpio::Configuration F446re::button_cfg{
		drivers::peripherals::gpio::Configuration::Channel::c,
		drivers::peripherals::gpio::Configuration::Pin_num::thirteen,
		drivers::peripherals::gpio::Configuration::Mode::in,
		drivers::peripherals::gpio::Configuration::Out_type::push_pull,
		drivers::peripherals::gpio::Configuration::Pull_mode::none,
		drivers::peripherals::gpio::Configuration::Speed::fast,
		drivers::peripherals::gpio::Configuration::Alternate_function::zero,
	};

	const drivers::peripherals::gpio::Configuration F446re::led_cfg{
		drivers::peripherals::gpio::Configuration::Channel::a,
		drivers::peripherals::gpio::Configuration::Pin_num::five,
		drivers::peripherals::gpio::Configuration::Mode::out,
		drivers::peripherals::gpio::Configuration::Out_type::push_pull,
		drivers::peripherals::gpio::Configuration::Pull_mode::none,
		drivers::peripherals::gpio::Configuration::Speed::fast,
		drivers::peripherals::gpio::Configuration::Alternate_function::zero,
	};
} // namespace nucleo