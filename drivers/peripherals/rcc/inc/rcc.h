/*
 * rcc.h
 *
 *  Created on: Nov 15, 2020
 *      Author: joaquin.alvidrez
 */

#ifndef PERIPHERALS_RCC_INC_RCC_H_
#define PERIPHERALS_RCC_INC_RCC_H_

#include "drivers/peripherals/gpio/inc/configuration.h"

namespace mcal
{
    namespace peripherals
    {
        namespace rcc
        {
            namespace gpio
            {
                void set_clock_enabled(
                    peripherals::gpio::Configuration::Channel channel,
                    bool b_set);

                void reset_reg(
                    peripherals::gpio::Configuration::Channel channel);
            } // namespace gpio
        }     // namespace rcc
    }         // namespace peripherals

} // namespace mcal

#endif /* PERIPHERALS_RCC_INC_RCC_H_ */
