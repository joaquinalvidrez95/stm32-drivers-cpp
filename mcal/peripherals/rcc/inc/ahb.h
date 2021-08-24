/*
 * ahb.h
 *
 *  Created on: Aug 11, 2021
 *      Author: joaquin
 */

#ifndef PERIPHERALS_RCC_INC_AHB_H_
#define PERIPHERALS_RCC_INC_AHB_H_

#include <cstddef>
#include <cstdint>

namespace mcal::peripherals::rcc::ahb
{
    enum class bus : size_t
    {
        one,
        two,
        three,
        total,
    };

    enum class one_bits : uint32_t
    {
        gpioa,
        gpiob,
        gpioc,
        gpiod,
        gpioe,
        gpiof,
        gpiog,
        gpioh,
        _reserved1,
        _reserved2,
        _reserved3,
        _reserved4,
        crc,
        _reserved5,
        _reserved6,
        _reserved7,
        _reserved8,
        _reserved9,
        bkpsram,
        _reserved10,
        _reserved11,
        dma1,
        dma2,
        _reserved12,
        _reserved13,
        _reserved14,
        _reserved15,
        _reserved16,
        _reserved17,
        otghs,
        otghsulpi,
    };

} // namespace mcal::peripherals::rcc::ahb

#endif /* PERIPHERALS_RCC_INC_AHB_H_ */
