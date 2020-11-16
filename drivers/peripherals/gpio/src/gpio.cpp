/*
 * stm32f446xx_gpio_driver.c
 *
 *  Created on: May 19, 2020
 *      Author: joaquin
 */

#include "drivers/peripherals/gpio/inc/gpio.h"

#include <cstddef>
#include <stdint.h>

#include "drivers/peripherals/rcc/inc/rcc.h"

namespace drivers
{
    namespace peripherals
    {
        namespace gpio
        {
#if 0
            void gpio_deinit(gpio_reg_t *p_reg)
            {
                gpio_reset_t port = Gpio_reset_port_a;

                if (p_reg == GPIOA)
                {
                }
                else if (p_reg == GPIOB)
                {
                    port = Gpio_reset_port_b;
                }
                else if (p_reg == GPIOC)
                {
                    port = Gpio_reset_port_c;
                }
                else if (p_reg == GPIOD)
                {
                    port = Gpio_reset_port_d;
                }
                else if (p_reg == GPIOE)
                {
                    port = Gpio_reset_port_e;
                }
                else if (p_reg == GPIOF)
                {
                    port = Gpio_reset_port_f;
                }
                else if (p_reg == GPIOG)
                {
                    port = Gpio_reset_port_g;
                }
                else if (p_reg == GPIOH)
                {
                    port = Gpio_reset_port_h;
                }
                GPIOX_REG_RESET(port);
            }

           

            gpio_button_state_t gpio_read_pin(const gpio_handle_t *p_handle)
            {
                return (gpio_button_state_t)((p_handle->p_reg->IDR >> p_handle->cfg.number) & 1u);
            }

            uint16_t gpio_read_port(gpio_reg_t *p_reg)
            {
                return (uint16_t)(p_reg->IDR);
            }

            void gpio_write_pin(gpio_handle_t *p_handle, gpio_pin_status_t value)
            {
                if (value == GPIO_PIN_STATUS_SET)
                {
                    p_handle->p_reg->ODR |= 1u << p_handle->cfg.number;
                }
                else
                {
                    p_handle->p_reg->ODR &= ~(1u << p_handle->cfg.number);
                }
            }

            void gpio_write_port(gpio_reg_t *p_reg, uint16_t value)
            {
                p_reg->ODR = value;
            }

            void gpio_toggle_pin(gpio_handle_t *p_handle)
            {
                p_handle->p_reg->ODR ^= 1u << p_handle->cfg.number;
            }

            void gpio_config_irq(nvic_irq_num_t irq_number, bool b_enable)
            {
                /* TODO: Get IRQ automatically */
            }

            void gpio_config_irq_priority(nvic_irq_num_t irq_number, nvic_irq_prio_t priority)
            {
            }

            void gpio_irq_handling(gpio_pin_t pin)
            {
                if (EXTI->PR & (1 << pin))
                {
                    /* Clears */
                    EXTI->PR |= 1 << pin;
                }
            }
#endif
            Gpio_handle::Gpio_handle(const Configuration &cfg)
                : m_cfg{cfg},
                  mp_reg{Gpio_handle::p_registers[static_cast<std::size_t>(m_cfg.channel)]}
            {
            }

            void Gpio_handle::init()
            {
                Rcc::set_gpio_clock_enabled(m_cfg.channel, true);

                /* TODO: Check if memset */
                /* Configures mode. */
                if (m_cfg.mode <= Configuration::Mode::analog)
                {
                    mp_reg->MODER &= ~(0x3u << (2u * m_cfg.number));
                    mp_reg->MODER |= static_cast<uint32_t>(m_cfg.mode) << (2u * m_cfg.number);
                }
                else
                {
                    switch (m_cfg.mode)
                    {
                    case Configuration::Mode::interrupt_falling_transition:
                        EXTI->FTSR |= 1u << m_cfg.number;
                        EXTI->RTSR &= ~(1u << m_cfg.number);
                        break;

                    case Configuration::Mode::interrupt_rising_transition:
                        EXTI->RTSR |= 1u << m_cfg.number;
                        EXTI->FTSR &= ~(1u << m_cfg.number);
                        break;

                    case Configuration::Mode::interrupt_rft:
                        EXTI->RTSR |= 1u << m_cfg.number;
                        EXTI->FTSR |= 1u << m_cfg.number;
                        break;

                    default:
                        break;
                    }
                    /* Configures the GPIO port selection in SYSCFG_EXTICR */

                    SYSCFG_PCLK_EN();
                    size_t index = m_cfg.number / 4u;
                    uint8_t section = m_cfg.number % 4u;
                    SYSCFG->EXTICR[index] = (uint32_t)Driver_gpio_address_to_code(mp_reg) << (section * 4u);
                    EXTI->IMR |= 1u << m_cfg.number;
                }

                /* Configures speed. */
                mp_reg->OSPEEDER &= ~(0x3u << (2 * m_cfg.number));
                mp_reg->OSPEEDER |= m_cfg.speed << (2 * m_cfg.number);

                /* Configures pupd. */
                mp_reg->PUPDR &= ~(0x3u << (2 * m_cfg.number));
                mp_reg->PUPDR |= m_cfg.pull_mode << (2 * m_cfg.number);

                /* Configures opt type. */
                mp_reg->OTYPER &= ~(0x1u << m_cfg.number);
                mp_reg->OTYPER |= (uint32_t)m_cfg.out_type << (uint32_t)m_cfg.number;

                /* Configures alternate function */
                if (m_cfg.mode == Configuration::Mode::alternate_function)
                {
                    const uint32_t temp1 = m_cfg.number / 8u;
                    const uint32_t tmp2 = m_cfg.number % 8u;
                    mp_reg->AFR[temp1] &= ~(0xFu << (4 * tmp2));
                    mp_reg->AFR[temp1] |= m_cfg.alt_fun_mode << (4 * tmp2);
                }
            }

            void Gpio_handle::toggle_pin()
            {
                mp_reg->ODR ^= 1u << m_cfg.number;
            }

            gpio_reg_t *const Gpio_handle::p_registers[static_cast<std::size_t>(Configuration::Channel::total)] = {
                GPIOA,
                GPIOB,
                GPIOC,
                GPIOD,
                GPIOE,
                GPIOF,
                GPIOG,
                GPIOH,
            };
        } // namespace gpio

    } // namespace peripherals

} // namespace drivers
