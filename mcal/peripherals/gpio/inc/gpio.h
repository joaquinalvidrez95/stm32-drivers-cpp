/**
 * @file gpio.h
 * @author Joaquin Alan Alvidrez Soto
 * @brief 
 * @date 2021-08-23
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef MCAL_PERIPHERALS_GPIO_INC_GPIO_H
#define MCAL_PERIPHERALS_GPIO_INC_GPIO_H

namespace mcal::peripherals::gpio
{
    enum class pin_state
    {
        reset,
        set
    };
} // namespace mcal::peripherals::gpio

#endif // MCAL_PERIPHERALS_GPIO_INC_GPIO_H
