/*
 * rcc.h
 *
 *  Created on: Nov 15, 2020
 *      Author: joaquin.alvidrez
 */

#ifndef PERIPHERALS_RCC_INC_RCC_H_
#define PERIPHERALS_RCC_INC_RCC_H_

#include "drivers/peripherals/gpio/inc/configuration.h"

namespace drivers
{
    namespace peripherals
    {
        namespace rcc
        {
            void set_gpio_clock_enabled(gpio::Configuration::Channel channel, bool b_set);
            void reset_gpio_reg(gpio::Configuration::Channel channel);

        } // namespace rcc

    } // namespace peripherals

} // namespace drivers

#endif /* PERIPHERALS_RCC_INC_RCC_H_ */
