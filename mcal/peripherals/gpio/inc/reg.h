#ifndef DRIVERS_PERIPHERALS_GPIO_REG_H__
#define DRIVERS_PERIPHERALS_GPIO_REG_H__

#include <stdint.h>

#include "mcal/inc/stm32f446xx.h"

namespace mcal::peripherals::gpio
{
    struct reg
    {
        volatile uint32_t moder;
        volatile uint32_t otyper;
        volatile uint32_t ospeeder;
        volatile uint32_t pupdr;
        volatile uint32_t idr;
        volatile uint32_t odr;
        volatile uint32_t bsrr;
        volatile uint32_t lckr;
        volatile uint32_t afr[2];
    };

} // namespace mcal::peripherals::gpio

#endif // DRIVERS_PERIPHERALS_GPIO_REG_H__
