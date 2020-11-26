/*
 * stm32f446xx_gpio_driver.h
 *
 *  Created on: May 19, 2020
 *      Author: joaquin
 */

#ifndef INC_STM32F446XX_GPIO_DRIVER_H_
#define INC_STM32F446XX_GPIO_DRIVER_H_

#include <array>

#include "drivers/cortex/inc/nvic.h"

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <cstddef>

#include "drivers/inc/stm32f446xx.h"
#include "drivers/peripherals/gpio/inc/configuration.h"

    namespace drivers
    {
        namespace peripherals
        {
            namespace gpio
            {

                enum class Pin_state : uint32_t
                {
                    reset,
                    set
                };

                class Handle
                {
                    /* TODO: Add const specifier to methods */
                public:
                    Handle(const Configuration *p_cfg = nullptr);
                    void init(const Configuration *p_cfg = nullptr);
                    void toggle_pin();
                    void deinit();
                    Pin_state read_pin();
                    uint16_t read_port();
                    void write_pin(Pin_state state);
                    void write_port(uint16_t value);
                    void set_irq_enabled(bool b_enabled);
                    void config_irq_priority(cortex::nvic::Irq_prio prio);
                    void handle_irq();

                private:
                    const Configuration *mp_cfg;
                    static constexpr std::array<gpio_reg_t *, static_cast<std::size_t>(Configuration::Channel::total)> p_registers{
                        GPIOA,
                        GPIOB,
                        GPIOC,
                        GPIOD,
                        GPIOE,
                        GPIOF,
                        GPIOG,
                        GPIOH,
                    };
                    static constexpr std::array<cortex::nvic::Irq_num, static_cast<std::size_t>(Configuration::Pin_num::total)> irq_nums{
                        cortex::nvic::Irq_num::exti0,
                        cortex::nvic::Irq_num::exti1,
                        cortex::nvic::Irq_num::exti2,
                        cortex::nvic::Irq_num::exti3,
                        cortex::nvic::Irq_num::exti4,
                        cortex::nvic::Irq_num::exti9_5,
                        cortex::nvic::Irq_num::exti9_5,
                        cortex::nvic::Irq_num::exti9_5,
                        cortex::nvic::Irq_num::exti9_5,
                        cortex::nvic::Irq_num::exti9_5,
                        cortex::nvic::Irq_num::exti15_10,
                        cortex::nvic::Irq_num::exti15_10,
                        cortex::nvic::Irq_num::exti15_10,
                        cortex::nvic::Irq_num::exti15_10,
                        cortex::nvic::Irq_num::exti15_10,
                        cortex::nvic::Irq_num::exti15_10,
                    };

                    inline gpio_reg_t *reg() const
                    {
                        return mp_cfg ? Handle::p_registers.at(static_cast<std::size_t>(mp_cfg->channel)) : nullptr;
                    }
                };

            } // namespace gpio
        }     // namespace peripherals

    } // namespace drivers

#ifdef __cplusplus
}
#endif

#endif /* INC_STM32F446XX_GPIO_DRIVER_H_ */
