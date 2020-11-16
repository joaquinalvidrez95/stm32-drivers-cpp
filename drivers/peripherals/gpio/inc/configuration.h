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

    namespace drivers
    {
        namespace peripherals
        {
            namespace gpio
            {

                struct Configuration
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
                        interrupt_falling_transition = 4u,
                        interrupt_rising_transition = 5u,
                        interrupt_rft = 6u,
                    };

                    typedef enum
                    {
                        GPIO_OUT_TYPE_PUSH_PULL = 0u,
                        GPIO_OUT_TYPE_OPEN_DRAIN = 1u,
                    } gpio_out_type_t;

                    typedef enum
                    {
                        GPIO_SPEED_LOW = 0u,
                        GPIO_SPEED_MED = 1u,
                        GPIO_SPEED_FAST = 2u,
                        GPIO_SPEED_HIGH = 3u,
                    } gpio_speed_t;

                    typedef enum
                    {
                        GPIO_PULL_MODE_NONE = 0u,
                        GPIO_PULL_MODE_UP = 1u,
                        GPIO_PULL_MODE_DOWN = 2u,
                    } gpio_pull_mode_t;

                    typedef enum
                    {
                        GPIO_PIN_0 = 0u,
                        GPIO_PIN_1,
                        GPIO_PIN_2,
                        GPIO_PIN_3,
                        GPIO_PIN_4,
                        GPIO_PIN_5,
                        GPIO_PIN_6,
                        GPIO_PIN_7,
                        GPIO_PIN_8,
                        GPIO_PIN_9,
                        GPIO_PIN_10,
                        GPIO_PIN_11,
                        GPIO_PIN_12,
                        GPIO_PIN_13,
                        GPIO_PIN_14,
                        GPIO_PIN_15,
                        GPIO_PIN_16,
                    } gpio_pin_t;

                    typedef enum
                    {
                        GPIO_BUTTON_STATE_LOW = 0u,
                        GPIO_BUTTON_STATE_HIGH = 1u,
                    } gpio_button_state_t;

                    typedef enum
                    {
                        GPIO_ALTERNATE_FUNCTION_0 = 0u,
                        GPIO_ALTERNATE_FUNCTION_1,
                        GPIO_ALTERNATE_FUNCTION_2,
                        GPIO_ALTERNATE_FUNCTION_3,
                        GPIO_ALTERNATE_FUNCTION_4,
                        GPIO_ALTERNATE_FUNCTION_5,
                        GPIO_ALTERNATE_FUNCTION_6,
                        GPIO_ALTERNATE_FUNCTION_7,
                        GPIO_ALTERNATE_FUNCTION_8,
                        GPIO_ALTERNATE_FUNCTION_9,
                        GPIO_ALTERNATE_FUNCTION_10,
                        GPIO_ALTERNATE_FUNCTION_11,
                        GPIO_ALTERNATE_FUNCTION_12,
                        GPIO_ALTERNATE_FUNCTION_13,
                        GPIO_ALTERNATE_FUNCTION_14,
                        GPIO_ALTERNATE_FUNCTION_15,
                    } gpio_alternate_function_t;

                    gpio_pin_t number;
                    Mode mode;
                    gpio_speed_t speed;
                    gpio_pull_mode_t pull_mode;
                    gpio_out_type_t out_type;
                    gpio_alternate_function_t alt_fun_mode;
                    Channel channel;
                };
            } // namespace gpio
        }     // namespace peripherals
    } // namespace drivers

#ifdef __cplusplus
}
#endif

#endif /* PERIPHERALS_GPIO_INC_CONFIGURATION_H_ */
