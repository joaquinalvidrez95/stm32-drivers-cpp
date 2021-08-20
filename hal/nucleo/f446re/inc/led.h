/*
 * led.h
 *
 *  Created on: Aug 11, 2021
 *      Author: joaquin
 */

#ifndef NUCLEO_F446RE_INC_LED_H_
#define NUCLEO_F446RE_INC_LED_H_

#include "mcal/peripherals/gpio/inc/handle.h"
#include "mcal/peripherals/gpio/inc/configuration.h"

namespace hal::nucleo::f446re
{
    class Led
    {
    public:
        Led();
        void toggle() const;

    private:
        const mcal::peripherals::gpio::Handle handle_;
    };

} // namespace hal::nucleo::f446re

#endif /* NUCLEO_F446RE_INC_LED_H_ */
