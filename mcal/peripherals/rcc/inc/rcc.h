/*
 * rcc.h
 *
 *  Created on: Nov 15, 2020
 *      Author: joaquin.alvidrez
 */

#ifndef PERIPHERALS_RCC_INC_RCC_H_
#define PERIPHERALS_RCC_INC_RCC_H_

#include "mcal/peripherals/gpio/inc/ext.h"
#include "mcal/peripherals/spi/inc/ext.h"

namespace mcal::peripherals::rcc
{
    void set_system_cfg_ctrl_clock_enabled(bool b_enabled);

    void set_clock_enabled(peripherals::gpio::channel channel, bool b_set);

    void reset_reg(peripherals::gpio::channel channel);

    void set_clock_enabled(peripherals::spi::bus bus, bool b_set);

    void reset_reg(peripherals::spi::bus bus);

} // namespace mcal::peripherals::rcc

#endif /* PERIPHERALS_RCC_INC_RCC_H_ */
