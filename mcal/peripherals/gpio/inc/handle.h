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
#include "mcal/peripherals/gpio/inc/gpio.h"

    namespace mcal::peripherals::gpio
    {
        class handle
        {
        public:
            handle(const Cfg &cfg);
            ~handle();
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
            void init_registers();

            const Cfg &cfg_;

            Reg *const p_reg_;
        };

    } // namespace mcal::peripherals::gpio

#ifdef __cplusplus
}
#endif

#endif /* INC_STM32F446XX_GPIO_DRIVER_H_ */
