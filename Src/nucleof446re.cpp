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

	void F446re::init_button(drivers::peripherals::Mechanism mechanism)
	{
		h_button_.init((drivers::peripherals::Mechanism::interrupt == mechanism) ? &interrupt_button_cfg : nullptr);
	}

	void F446re::wait_till_button_pressed()
	{
		while (!is_button_pressed())
		{
		}
		utils::delay();
	}

	bool F446re::is_button_pressed()
	{
		return drivers::peripherals::gpio::Pin_state::reset == h_button_.read_pin();
	}

	void F446re::init_led()
	{
		h_led_.init();
	}

	void F446re::toggle_led()
	{
		h_led_.toggle_pin();
	}

	void F446re::handle_irq_button()
	{
		h_button_.handle_irq();
	}

	void F446re::set_button_irq_enabled(bool b_enabled)
	{
		h_button_.set_irq_enabled(b_enabled);
	}

	constexpr drivers::peripherals::gpio::Configuration F446re::button_cfg;
	constexpr drivers::peripherals::gpio::Configuration F446re::led_cfg;
	constexpr drivers::peripherals::gpio::Configuration F446re::interrupt_button_cfg;
} // namespace nucleo