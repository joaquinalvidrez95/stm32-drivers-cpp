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
#include "utils.h"

namespace drivers
{
    namespace peripherals
    {
        namespace gpio
        {
            Handle::Handle(const Configuration &cfg)
                : m_cfg{cfg},
                  mp_reg{Handle::p_registers[static_cast<std::size_t>(m_cfg.channel)]}
            {
            }

            void Handle::init()
            {
                rcc::set_gpio_clock_enabled(m_cfg.channel, true);

                /* TODO: Check if memset */
                /* Configures mode. */
                if (m_cfg.mode <= Configuration::Mode::analog)
                {
                    mp_reg->moder &= ~(0x3u << (2u * static_cast<uint32_t>(m_cfg.pin_num)));
                    mp_reg->moder |= static_cast<uint32_t>(m_cfg.mode) << (2u * static_cast<uint32_t>(m_cfg.pin_num));
                }
                else
                {
                    /* TODO: Use utils */
                    switch (m_cfg.mode)
                    {
                    case Configuration::Mode::falling_transition_interrupt:
                        EXTI->ftsr |= 1u << static_cast<uint32_t>(m_cfg.pin_num);
                        EXTI->rtsr &= ~(1u << static_cast<uint32_t>(m_cfg.pin_num));
                        break;

                    case Configuration::Mode::rising_transition_interrupt:
                        EXTI->rtsr |= 1u << static_cast<uint32_t>(m_cfg.pin_num);
                        EXTI->ftsr &= ~(1u << static_cast<uint32_t>(m_cfg.pin_num));
                        break;

                    case Configuration::Mode::rising_falling_transition_interrupt:
                        EXTI->rtsr |= 1u << static_cast<uint32_t>(m_cfg.pin_num);
                        EXTI->ftsr |= 1u << static_cast<uint32_t>(m_cfg.pin_num);
                        break;

                    default:
                        break;
                    }

                    /* Configures the GPIO port selection in SYSCFG_EXTICR */
                    SYSCFG_PCLK_EN();
                    constexpr uint32_t num_bits_per_section{4u};
                    const uint32_t idx = static_cast<uint32_t>(m_cfg.pin_num) / num_bits_per_section;
                    const uint32_t section = static_cast<uint32_t>(m_cfg.pin_num) % num_bits_per_section;
                    SYSCFG->exticr[idx] = static_cast<uint32_t>(m_cfg.channel) << (section * num_bits_per_section);
                    EXTI->imr |= 1u << static_cast<uint32_t>(m_cfg.pin_num);
                }

                /* Configures speed. */
                mp_reg->ospeeder &= ~(0x3u << (2 * static_cast<uint32_t>(m_cfg.pin_num)));
                mp_reg->ospeeder |= static_cast<uint32_t>(m_cfg.speed) << (2 * static_cast<uint32_t>(m_cfg.pin_num));

                /* Configures pupd. */
                mp_reg->pupdr &= ~(0x3u << (2 * static_cast<uint32_t>(m_cfg.pin_num)));
                mp_reg->pupdr |= static_cast<uint32_t>(m_cfg.pull_mode) << (2 * static_cast<uint32_t>(m_cfg.pin_num));

                /* Configures opt type. */
                mp_reg->otyper &= ~(0x1u << static_cast<uint32_t>(m_cfg.pin_num));
                mp_reg->otyper |= static_cast<uint32_t>(m_cfg.out_type) << static_cast<uint32_t>(m_cfg.pin_num);

                /* Configures alternate function */
                if (Configuration::Mode::alternate_function == m_cfg.mode)
                {
                    /* TODO: Refactor */
                    const uint32_t tmp1 = static_cast<uint32_t>(m_cfg.pin_num) / 8u;
                    const uint32_t tmp2 = static_cast<uint32_t>(m_cfg.pin_num) % 8u;
                    mp_reg->afr[tmp1] &= ~(0xFu << (4 * tmp2));
                    mp_reg->afr[tmp1] |= static_cast<uint32_t>(m_cfg.alt_fun_mode) << (4 * tmp2);
                }
            }

            void Handle::toggle_pin()
            {
                mp_reg->odr ^= 1u << static_cast<uint32_t>(m_cfg.pin_num);
            }

            void Handle::deinit()
            {
                rcc::reset_gpio_reg(m_cfg.channel);
            }

            Pin_state Handle::read_pin()
            {
                return Utils::is_bit_set(mp_reg->idr, static_cast<uint32_t>(m_cfg.pin_num)) ? Pin_state::set : Pin_state::reset;
            }

            uint16_t Handle::read_port()
            {
                return static_cast<uint16_t>(mp_reg->idr);
            }

            void Handle::write_pin(Pin_state state)
            {
                Utils::set_bit_by_position(mp_reg->odr, static_cast<uint32_t>(m_cfg.pin_num), Pin_state::set == state);
            }

            void Handle::write_port(uint16_t value)
            {
                mp_reg->odr = value;
            }

            void Handle::config_irq(nvic_irq_num_t irq_number, bool b_enable)
            {
                /* TODO: Implement */
            }

            void Handle::config_irq_priority(nvic_irq_num_t irq_number, nvic_irq_prio_t priority)
            {
                /* TODO: implement */
            }

            void Handle::handle_irq()
            {
                const auto pin_number{static_cast<uint32_t>(m_cfg.pin_num)};
                if (Utils::is_bit_set(EXTI->pr, pin_number))
                {
                    Utils::set_bit_by_position(EXTI->pr, pin_number, true);
                }
            }

            gpio_reg_t *const Handle::p_registers[static_cast<std::size_t>(Configuration::Channel::total)] = {
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
