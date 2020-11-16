/*
 * stm32f446xx_gpio_driver.h
 *
 *  Created on: May 19, 2020
 *      Author: joaquin
 */

#ifndef INC_STM32F446XX_GPIO_DRIVER_H_
#define INC_STM32F446XX_GPIO_DRIVER_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <cstddef>

#include "drivers/inc/stm32f446xx.h"
#include "drivers/cortex/inc/nvic.h"
#include "drivers/peripherals/gpio/inc/configuration.h"

    namespace drivers
    {
        namespace peripherals
        {
            namespace gpio
            {

                typedef enum
                {
                    GPIO_PIN_STATUS_RESET = 0u,
                    GPIO_PIN_STATUS_SET = 1u,
                } gpio_pin_status_t;

                void gpio_deinit(gpio_reg_t *p_reg);

#if 0
                gpio_button_state_t gpio_read_pin(const gpio_handle_t *p_handle);
                uint16_t gpio_read_port(gpio_reg_t *p_reg);
                void gpio_write_pin(gpio_handle_t *p_handle, gpio_pin_status_t value);
                void gpio_write_port(gpio_reg_t *p_reg, uint16_t value);
                void gpio_toggle_pin(gpio_handle_t *p_handle);

                void gpio_config_irq(nvic_irq_num_t irq_number, bool b_enable);
                void gpio_config_irq_priority(nvic_irq_num_t irq_number, nvic_irq_prio_t priority);
                void gpio_irq_handling(gpio_pin_t pin);
#endif
                class Gpio_handle
                {
                public:
                    Gpio_handle(const Configuration &cfg);
                    void init();
                    void toggle_pin();

                private:
                    const Configuration &m_cfg;
                    gpio_reg_t *const mp_reg = nullptr;
                    static gpio_reg_t *const p_registers[static_cast<std::size_t>(Configuration::Channel::total)];
                };

            } // namespace gpio
        }     // namespace peripherals

    } // namespace drivers

#ifdef __cplusplus
}
#endif

#endif /* INC_STM32F446XX_GPIO_DRIVER_H_ */
