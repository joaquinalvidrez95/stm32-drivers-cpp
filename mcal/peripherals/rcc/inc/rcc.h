/*
 * rcc.h
 *
 *  Created on: Nov 15, 2020
 *      Author: joaquin.alvidrez
 */

#ifndef PERIPHERALS_RCC_INC_RCC_H_
#define PERIPHERALS_RCC_INC_RCC_H_

#include "mcal/peripherals/gpio/inc/configuration.h"
#include "mcal/peripherals/spi/inc/cfg.h"

namespace mcal
{
    namespace peripherals
    {
        namespace rcc
        {
            void set_system_cfg_ctrl_clock_enabled(bool b_enabled);

            namespace gpio
            {
                void set_clock_enabled(
                    peripherals::gpio::Configuration::Channel channel,
                    bool b_set);

                void reset_reg(
                    peripherals::gpio::Configuration::Channel channel);
            } // namespace gpio

            void set_clock_enabled(
                peripherals::gpio::Configuration::Channel channel,
                bool b_set);

            void reset_reg(peripherals::gpio::Configuration::Channel channel);

            void set_clock_enabled(peripherals::spi::Configuration::Bus bus,
                                   bool b_set);

            void reset_reg(peripherals::spi::Configuration::Bus bus);
        } // namespace rcc
    }     // namespace peripherals

} // namespace mcal

#endif /* PERIPHERALS_RCC_INC_RCC_H_ */
