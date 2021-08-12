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
                in = 0u,
                out = 1u,
                alternate_function = 2u,
                analog = 3u,

                /* Interrupts */
                falling_transition_interrupt = 4u,
                rising_transition_interrupt = 5u,
                rising_falling_transition_interrupt = 6u,
            };

            enum class Out_type : uint32_t
            {
                push_pull = 0u,
                open_drain = 1u,
            };

            enum class Speed : uint32_t
            {
                low = 0u,
                medium = 1u,
                fast = 2u,
                high = 3u,
            };

            enum class Pull_mode : uint32_t
            {
                none = 0u,
                up = 1u,
                down = 2u,
            };

            enum class Pin_num : uint32_t
            {
                zero = 0u,
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
                zero = 0u,
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
