/*
 * aph.h
 *
 *  Created on: Aug 11, 2021
 *      Author: joaquin
 */

#ifndef PERIPHERALS_RCC_INC_APH_H_
#define PERIPHERALS_RCC_INC_APH_H_

#include <cstddef>
#include <cstdint>

namespace mcal::peripherals::rcc::apb
{
    enum class bus : size_t
    {
        one,
        two,
        total,
    };

    enum class one_bits : uint32_t
    {
        tim2,
        tim3,
        tim4,
        tim5,
        tim6,
        tim7,
        tim12,
        tim13,
        tim14,
        _reserved1,
        _reserved2,
        wwdg,
        _reserved3,
        _reserved4,
        spi2,
        spi3,
        spdifrx,
        usart2,
        usart3,
        uart4,
        uart5,
        i2c1,
        i2c2,
        i2c3,
        fmpi2c1,
        can1,
        can2,
        cec,
        pwr,
        dac,
    };

    enum class two_bits : uint32_t
    {
        tim1,
        tim8,
        _reserved1,
        _reserved2,
        usart1,
        usart6,
        _reserved3,
        _reserved4,
        adc1,
        adc2,
        adc3,
        sdio,
        spi1,
        spi4,
        syscfg,
        _reserved5,
        tim9,
        tim10,
        tim11,
        _reserved6,
        _reserved7,
        _reserved8,
        sai1,
        sai2
    };

} // namespace mcal::peripherals::rcc::apb

#endif /* PERIPHERALS_RCC_INC_APH_H_ */
