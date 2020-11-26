/*
 * nucleof446re.h
 *
 *  Created on: Nov 22, 2020
 *      Author: joaquin.alvidrez
 */

#ifndef NUCLEOF446RE_H_
#define NUCLEOF446RE_H_

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
		static const drivers::peripherals::gpio::Configuration button_cfg;
		static const drivers::peripherals::gpio::Configuration led_cfg;
		drivers::peripherals::gpio::Handle mh_button{button_cfg};
		drivers::peripherals::gpio::Handle mh_led{led_cfg};
	};
} // namespace nucleo

#endif /* NUCLEOF446RE_H_ */
