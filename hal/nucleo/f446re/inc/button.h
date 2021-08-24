/*
 * button.h
 *
 *  Created on: Aug 11, 2021
 *      Author: joaquin
 */

#ifndef NUCLEO_F446RE_INC_BUTTON_H_
#define NUCLEO_F446RE_INC_BUTTON_H_

#include "mcal/peripherals/gpio/inc/ext.h"
#include "mcal/peripherals/inc/mechanism.h"

namespace hal::nucleo::f446re
{
    class button
    {
    public:
        button(mcal::peripherals::mechanism mechanism =
                   mcal::peripherals::mechanism::polling);
        void wait_till_pressed() const;
        bool is_pressed() const;
        void handle_irq() const;

    private:
        const mcal::peripherals::gpio::handle handle_;
    };
} // namespace hal::nucleo::f446re

#endif /* NUCLEO_F446RE_INC_BUTTON_H_ */
