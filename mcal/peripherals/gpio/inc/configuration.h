/*
 * configuration.h
 *
 *  Created on: Nov 15, 2020
 *      Author: joaquin.alvidrez
 */

#ifndef PERIPHERALS_GPIO_INC_CONFIGURATION_H_
#define PERIPHERALS_GPIO_INC_CONFIGURATION_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdint.h>

    namespace mcal::peripherals::gpio
    {

        enum class channel
        {
            a,
            b,
            c,
            d,
            e,
            f,
            g,
            h,
            total
        };

        enum class mode : uint32_t
        {
            in,
            out,
            alternate_function,
            analog,

            /* Interrupts */
            falling_transition_interrupt,
            rising_transition_interrupt,
            rising_falling_transition_interrupt,
        };

        enum class out_type : uint32_t
        {
            push_pull,
            open_drain,
        };

        enum class speed : uint32_t
        {
            low,
            medium,
            fast,
            high,
        };

        enum class pull_mode : uint32_t
        {
            none,
            up,
            down,
        };

        enum class pin_num : uint32_t
        {
            p0,
            p1,
            p2,
            p3,
            p4,
            p5,
            p6,
            p7,
            p8,
            p9,
            p10,
            p11,
            p12,
            p13,
            p14,
            p15,
            total,
        };

        enum class alternate_function : uint32_t
        {
            f0,
            f1,
            f2,
            f3,
            f4,
            f5,
            f6,
            f7,
            f8,
            f9,
            f10,
            f11,
            f12,
            f13,
            f14,
            f15,
        };

        struct cfg
        {
            gpio::channel channel;
            gpio::pin_num pin_num;
            gpio::mode mode;
            gpio::out_type out_type;
            gpio::pull_mode pull_mode;
            gpio::speed speed;
            alternate_function alt_fun_mode;
        };
    } // namespace mcal::peripherals::gpio

#ifdef __cplusplus
}
#endif

#endif /* PERIPHERALS_GPIO_INC_CONFIGURATION_H_ */
