/*
 * led.h
 *
 *  Created on: Aug 11, 2021
 *      Author: joaquin
 */

#ifndef NUCLEO_F446RE_INC_LED_H_
#define NUCLEO_F446RE_INC_LED_H_

#include "mcal/peripherals/gpio/inc/ext.h"

namespace hal::nucleo::f446re
{
    class led
    {
    public:
        led();
        void toggle() const;

    private:
        const mcal::peripherals::gpio::handle handle_;
    };

} // namespace hal::nucleo::f446re

#endif /* NUCLEO_F446RE_INC_LED_H_ */
