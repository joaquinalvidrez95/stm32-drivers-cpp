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

#include "drivers/peripherals/gpio/inc/reg.h"
#include "drivers/peripherals/gpio/inc/configuration.h"

    namespace mcal
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
                public:
                    Handle(const Configuration *p_cfg = nullptr);
                    void init(const Configuration *p_cfg = nullptr);
                    void toggle_pin() const;
                    void deinit() const;
                    Pin_state read_pin() const;
                    uint16_t read_port() const;
                    void write_pin(Pin_state state) const;
                    void write_port(uint16_t value) const;
                    void set_irq_enabled(bool b_enabled) const;
                    void config_irq_priority(cortex::nvic::Irq_prio prio) const;
                    void handle_irq() const;

                private:
                    const Configuration *p_cfg_;
                    static constexpr std::array<Reg *, static_cast<std::size_t>(Configuration::Channel::total)> p_registers{
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

                    inline Reg *reg() const
                    {
                        return p_cfg_ ? Handle::p_registers.at(static_cast<std::size_t>(p_cfg_->channel)) : nullptr;
                    }
                };

            } // namespace gpio
        }     // namespace peripherals

    } // namespace mcal

#ifdef __cplusplus
}
#endif

#endif /* INC_STM32F446XX_GPIO_DRIVER_H_ */
