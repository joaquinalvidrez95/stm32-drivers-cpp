/*
 * stm32f446xx_gpio_driver.h
 *
 *  Created on: May 19, 2020
 *      Author: joaquin
 */

#ifndef INC_STM32F446XX_GPIO_DRIVER_H_
#define INC_STM32F446XX_GPIO_DRIVER_H_

#include <array>

#include "mcal/cortex/inc/nvic.h"

#ifdef __cplusplus
extern "C"
{
#endif

#include <cstdint>
#include <cstddef>

#include "mcal/peripherals/gpio/inc/reg.h"
#include "mcal/peripherals/gpio/inc/configuration.h"

    namespace mcal::peripherals::gpio
    {

        enum class Pin_state : uint32_t
        {
            reset,
            set
        };

        class Handle
        {
        public:
            Handle(const Cfg *p_cfg = nullptr);
            ~Handle();
            void init(const Cfg *p_cfg = nullptr);
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
            const Cfg *p_cfg_;

            inline Reg *reg() const
            {
                static const std::array<Reg *const,
                                        static_cast<std::size_t>(Cfg::Channel::total)>
                    p_registers{
                        reinterpret_cast<Reg *>(address::ahb1::gpioa),
                        reinterpret_cast<Reg *>(address::ahb1::gpiob),
                        reinterpret_cast<Reg *>(address::ahb1::gpioc),
                        reinterpret_cast<Reg *>(address::ahb1::gpiod),
                        reinterpret_cast<Reg *>(address::ahb1::gpioe),
                        reinterpret_cast<Reg *>(address::ahb1::gpiof),
                        reinterpret_cast<Reg *>(address::ahb1::gpiog),
                        reinterpret_cast<Reg *>(address::ahb1::gpioh),
                    };
                return p_cfg_
                           ? p_registers.at(static_cast<std::size_t>(p_cfg_->channel))
                           : nullptr;
            }
        };

    } // namespace mcal::peripherals::gpio

#ifdef __cplusplus
}
#endif

#endif /* INC_STM32F446XX_GPIO_DRIVER_H_ */
