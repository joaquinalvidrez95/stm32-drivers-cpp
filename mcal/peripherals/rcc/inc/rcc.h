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

namespace mcal::peripherals::rcc
{
    void set_system_cfg_ctrl_clock_enabled(bool b_enabled);

    void set_clock_enabled(peripherals::gpio::Cfg::Channel channel, bool b_set);

    void reset_reg(peripherals::gpio::Cfg::Channel channel);

    void set_clock_enabled(peripherals::spi::Cfg::Bus bus, bool b_set);

    void reset_reg(peripherals::spi::Cfg::Bus bus);

} // namespace mcal::peripherals::rcc

#endif /* PERIPHERALS_RCC_INC_RCC_H_ */
