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
#include "drivers/cortex/inc/nvic.h"
#include "utils.h"

namespace drivers
{
    namespace peripherals
    {
        namespace gpio
        {
            Handle::Handle(const Configuration *p_cfg)
                : mp_cfg{p_cfg}
            {
            }

            void Handle::init(const Configuration *p_cfg)
            {
                if (p_cfg)
                {
                    mp_cfg = p_cfg;
                }

                rcc::set_gpio_clock_enabled(mp_cfg->channel, true);

                auto *const p_reg{reg()};

                /* TODO: Check if memset */
                /* Configures mode. */
                if (mp_cfg->mode <= Configuration::Mode::analog)
                {
                    p_reg->moder &= ~(0x3u << (2u * static_cast<uint32_t>(mp_cfg->pin_num)));
                    p_reg->moder |= static_cast<uint32_t>(mp_cfg->mode) << (2u * static_cast<uint32_t>(mp_cfg->pin_num));
                }
                else
                {
                    /* TODO: Use utils */
                    switch (mp_cfg->mode)
                    {
                    case Configuration::Mode::falling_transition_interrupt:
                        EXTI->ftsr |= 1u << static_cast<uint32_t>(mp_cfg->pin_num);
                        EXTI->rtsr &= ~(1u << static_cast<uint32_t>(mp_cfg->pin_num));
                        break;

                    case Configuration::Mode::rising_transition_interrupt:
                        EXTI->rtsr |= 1u << static_cast<uint32_t>(mp_cfg->pin_num);
                        EXTI->ftsr &= ~(1u << static_cast<uint32_t>(mp_cfg->pin_num));
                        break;

                    case Configuration::Mode::rising_falling_transition_interrupt:
                        EXTI->rtsr |= 1u << static_cast<uint32_t>(mp_cfg->pin_num);
                        EXTI->ftsr |= 1u << static_cast<uint32_t>(mp_cfg->pin_num);
                        break;

                    default:
                        break;
                    }

                    /* Configures the GPIO port selection in SYSCFG_EXTICR */
                    SYSCFG_PCLK_EN();
                    constexpr uint32_t num_bits_per_section{4u};
                    const uint32_t idx = static_cast<uint32_t>(mp_cfg->pin_num) / num_bits_per_section;
                    const uint32_t section = static_cast<uint32_t>(mp_cfg->pin_num) % num_bits_per_section;
                    SYSCFG->exticr[idx] = static_cast<uint32_t>(mp_cfg->channel) << (section * num_bits_per_section);
                    EXTI->imr |= 1u << static_cast<uint32_t>(mp_cfg->pin_num);
                }

                /* Configures speed. */
                p_reg->ospeeder &= ~(0x3u << (2u * static_cast<uint32_t>(mp_cfg->pin_num)));
                p_reg->ospeeder |= static_cast<uint32_t>(mp_cfg->speed) << (2 * static_cast<uint32_t>(mp_cfg->pin_num));

                /* Configures pupd. */
                p_reg->pupdr &= ~(0x3u << (2u * static_cast<uint32_t>(mp_cfg->pin_num)));
                p_reg->pupdr |= static_cast<uint32_t>(mp_cfg->pull_mode) << (2 * static_cast<uint32_t>(mp_cfg->pin_num));

                /* Configures opt type. */
                p_reg->otyper &= ~(0x1u << static_cast<uint32_t>(mp_cfg->pin_num));
                p_reg->otyper |= static_cast<uint32_t>(mp_cfg->out_type) << static_cast<uint32_t>(mp_cfg->pin_num);

                /* Configures alternate function */
                if (Configuration::Mode::alternate_function == mp_cfg->mode)
                {
                    /* TODO: Refactor */
                    const uint32_t tmp1 = static_cast<uint32_t>(mp_cfg->pin_num) / 8u;
                    const uint32_t tmp2 = static_cast<uint32_t>(mp_cfg->pin_num) % 8u;
                    p_reg->afr[tmp1] &= ~(0xFu << (4 * tmp2));
                    p_reg->afr[tmp1] |= static_cast<uint32_t>(mp_cfg->alt_fun_mode) << (4 * tmp2);
                }
            }

            void Handle::toggle_pin()
            {
                reg()->odr ^= 1u << static_cast<uint32_t>(mp_cfg->pin_num);
            }

            void Handle::deinit()
            {
                rcc::reset_gpio_reg(mp_cfg->channel);
            }

            Pin_state Handle::read_pin()
            {
                return Utils::is_bit_set(reg()->idr, static_cast<uint32_t>(mp_cfg->pin_num)) ? Pin_state::set : Pin_state::reset;
            }

            uint16_t Handle::read_port()
            {
                return static_cast<uint16_t>(reg()->idr);
            }

            void Handle::write_pin(Pin_state state)
            {
                Utils::set_bit_by_position(reg()->odr, static_cast<uint32_t>(mp_cfg->pin_num), Pin_state::set == state);
            }

            void Handle::write_port(uint16_t value)
            {
                reg()->odr = value;
            }

            void Handle::set_irq_enabled(bool b_enabled)
            {
                cortex::nvic::set_irq_enabled(Handle::irq_nums.at(static_cast<std::size_t>(mp_cfg->pin_num)), b_enabled);
            }

            void Handle::config_irq_priority(cortex::nvic::Irq_prio prio)
            {
                cortex::nvic::set_irq_priority(Handle::irq_nums.at(static_cast<std::size_t>(mp_cfg->pin_num)), prio);
            }

            void Handle::handle_irq()
            {
                const auto pin_number{static_cast<uint32_t>(mp_cfg->pin_num)};
                if (Utils::is_bit_set(EXTI->pr, pin_number))
                {
                    Utils::set_bit_by_position(EXTI->pr, pin_number, true);
                }
            }

            constexpr std::array<gpio_reg_t *, static_cast<std::size_t>(Configuration::Channel::total)> Handle::p_registers;
            constexpr std::array<cortex::nvic::Irq_num, static_cast<std::size_t>(Configuration::Pin_num::total)> Handle::irq_nums;

        } // namespace gpio

    } // namespace peripherals

} // namespace drivers
