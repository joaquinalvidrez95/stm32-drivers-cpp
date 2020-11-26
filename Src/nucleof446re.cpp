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

} // namespace nucleo