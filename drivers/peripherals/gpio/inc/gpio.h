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

                enum class Pin_state : uint32_t
                {
                    reset,
                    set
                };

                class Handle
                {
                public:
                    Handle(const Configuration &cfg);
                    void init();
                    void toggle_pin();
                    void deinit();
                    Pin_state read_pin();
                    uint16_t read_port();
                    void write_pin(Pin_state state);
                    void write_port(uint16_t value);
                    void config_irq(nvic_irq_num_t irq_number, bool b_enable);
                    void config_irq_priority(nvic_irq_num_t irq_number, nvic_irq_prio_t priority);
                    void handle_irq();

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
