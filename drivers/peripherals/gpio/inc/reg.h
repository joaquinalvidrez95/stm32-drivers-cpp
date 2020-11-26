#ifndef DRIVERS_PERIPHERALS_GPIO_REG_H__
#define DRIVERS_PERIPHERALS_GPIO_REG_H__

#include <stdint.h>

#include "drivers/inc/stm32f446xx.h"

namespace drivers
{
    namespace peripherals
    {
        namespace gpio
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
        } // namespace gpio

    } // namespace peripherals

} // namespace drivers

#define GPIOA ((drivers::peripherals::gpio::Reg *const)GPIOA_BASEADDR)
#define GPIOB ((drivers::peripherals::gpio::Reg *const)GPIOB_BASEADDR)
#define GPIOC ((drivers::peripherals::gpio::Reg *const)GPIOC_BASEADDR)
#define GPIOD ((drivers::peripherals::gpio::Reg *const)GPIOD_BASEADDR)
#define GPIOE ((drivers::peripherals::gpio::Reg *const)GPIOE_BASEADDR)
#define GPIOF ((drivers::peripherals::gpio::Reg *const)GPIOF_BASEADDR)
#define GPIOG ((drivers::peripherals::gpio::Reg *const)GPIOG_BASEADDR)
#define GPIOH ((drivers::peripherals::gpio::Reg *const)GPIOH_BASEADDR)

#endif // DRIVERS_PERIPHERALS_GPIO_REG_H__