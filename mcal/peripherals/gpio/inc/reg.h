#ifndef DRIVERS_PERIPHERALS_GPIO_REG_H__
#define DRIVERS_PERIPHERALS_GPIO_REG_H__

#include <stdint.h>

#include "mcal/inc/stm32f446xx.h"

namespace mcal::peripherals::gpio
{
    struct Reg
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

#define GPIOA (reinterpret_cast<Reg *>(GPIOA_BASEADDR))
#define GPIOB (reinterpret_cast<Reg *>(GPIOB_BASEADDR))
#define GPIOC (reinterpret_cast<Reg *>(GPIOC_BASEADDR))
#define GPIOD (reinterpret_cast<Reg *>(GPIOD_BASEADDR))
#define GPIOE (reinterpret_cast<Reg *>(GPIOE_BASEADDR))
#define GPIOF (reinterpret_cast<Reg *>(GPIOF_BASEADDR))
#define GPIOG (reinterpret_cast<Reg *>(GPIOG_BASEADDR))
#define GPIOH (reinterpret_cast<Reg *>(GPIOH_BASEADDR))

} // namespace mcal::peripherals::gpio

#endif // DRIVERS_PERIPHERALS_GPIO_REG_H__
