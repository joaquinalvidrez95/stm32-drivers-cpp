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

        struct Cfg
        {
            enum class Channel
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

            enum class Mode : uint32_t
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

            enum class Out_type : uint32_t
            {
                push_pull,
                open_drain,
            };

            enum class Speed : uint32_t
            {
                low,
                medium,
                fast,
                high,
            };

            enum class Pull_mode : uint32_t
            {
                none,
                up,
                down,
            };

            enum class Pin_num : uint32_t
            {
                zero,
                one,
                two,
                three,
                four,
                five,
                six,
                seven,
                eight,
                nine,
                ten,
                eleven,
                twelve,
                thirteen,
                fourteen,
                fifteen,
                total,
            };

            enum class Alternate_function : uint32_t
            {
                zero,
                one,
                two,
                three,
                four,
                five,
                six,
                seven,
                eight,
                nine,
                ten,
                eleven,
                twelve,
                thirteen,
                fourteen,
                fifteen,
            };

            Channel channel;
            Pin_num pin_num;
            Mode mode;
            Out_type out_type;
            Pull_mode pull_mode;
            Speed speed;
            Alternate_function alt_fun_mode;
        };
    } // namespace mcal::peripherals::gpio

#ifdef __cplusplus
}
#endif

#endif /* PERIPHERALS_GPIO_INC_CONFIGURATION_H_ */
