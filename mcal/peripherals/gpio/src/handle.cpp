/*
 * stm32f446xx_gpio_driver.c
 *
 *  Created on: May 19, 2020
 *      Author: joaquin
 */

#include "mcal/peripherals/gpio/inc/handle.h"

#include <cstddef>
#include <stdint.h>

#include "mcal/peripherals/rcc/inc/rcc.h"
#include "mcal/cortex/inc/nvic.h"
#include "utils.h"

namespace mcal
{
    namespace peripherals
    {
        namespace gpio
        {
            Handle::Handle(const Cfg *p_cfg)
                : p_cfg_{p_cfg}
            {
            }

            Handle::~Handle()
            {
                if (p_cfg_)
                {
                    deinit();
                }
            }

            void Handle::init(const Cfg *p_cfg)
            {
                if (p_cfg)
                {
                    p_cfg_ = p_cfg;
                }

                rcc::set_clock_enabled(p_cfg_->channel, true);

                auto *const p_reg{reg()};

                /* TODO: Check if memset */
                /* Configures mode. */
                if (p_cfg_->mode <= Cfg::Mode::analog)
                {
                    utils::set_bits_by_position<uint32_t>(p_reg->moder, 2u * static_cast<uint32_t>(p_cfg_->pin_num), false, 3u);
                    utils::set_bits_by_position(p_reg->moder, 2u * static_cast<uint32_t>(p_cfg_->pin_num), true, static_cast<uint32_t>(p_cfg_->mode));
                }
                else
                {
                    /* TODO: Use utils */
                    switch (p_cfg_->mode)
                    {
                    case Cfg::Mode::falling_transition_interrupt:
                        utils::set_bits_by_position(EXTI->ftsr, static_cast<uint32_t>(p_cfg_->pin_num), true);
                        utils::set_bits_by_position(EXTI->rtsr, static_cast<uint32_t>(p_cfg_->pin_num), false);
                        break;

                    case Cfg::Mode::rising_transition_interrupt:
                        utils::set_bits_by_position(EXTI->rtsr, static_cast<uint32_t>(p_cfg_->pin_num), true);
                        utils::set_bits_by_position(EXTI->ftsr, static_cast<uint32_t>(p_cfg_->pin_num), false);
                        break;

                    case Cfg::Mode::rising_falling_transition_interrupt:
                        utils::set_bits_by_position(EXTI->rtsr, static_cast<uint32_t>(p_cfg_->pin_num), true);
                        utils::set_bits_by_position(EXTI->ftsr, static_cast<uint32_t>(p_cfg_->pin_num), true);
                        break;

                    default:
                        break;
                    }

                    /* Configures the GPIO port selection in SYSCFG_EXTICR */
                    rcc::set_system_cfg_ctrl_clock_enabled(true);
                    constexpr uint32_t num_bits_per_section{4u};
                    const uint32_t idx = static_cast<uint32_t>(p_cfg_->pin_num) / num_bits_per_section;
                    const uint32_t section = static_cast<uint32_t>(p_cfg_->pin_num) % num_bits_per_section;
                    SYSCFG->exticr[idx] = static_cast<uint32_t>(p_cfg_->channel) << (section * num_bits_per_section);
                    utils::set_bits_by_position(EXTI->imr, static_cast<uint32_t>(p_cfg_->pin_num), true);
                }

                /* Configures speed. */
                utils::set_bits_by_position<uint32_t>(p_reg->ospeeder, 2u * static_cast<uint32_t>(p_cfg_->pin_num), false, 3u);
                utils::set_bits_by_position(p_reg->ospeeder, 2u * static_cast<uint32_t>(p_cfg_->pin_num), true, static_cast<uint32_t>(p_cfg_->speed));

                /* Configures pupd. */
                utils::set_bits_by_position<uint32_t>(p_reg->pupdr, 2u * static_cast<uint32_t>(p_cfg_->pin_num), false, 3u);
                utils::set_bits_by_position<uint32_t>(p_reg->pupdr, 2u * static_cast<uint32_t>(p_cfg_->pin_num), false, static_cast<uint32_t>(p_cfg_->pull_mode));

                /* Configures opt type. */
                utils::set_bits_by_position(p_reg->otyper, static_cast<uint32_t>(p_cfg_->pin_num), false);
                utils::set_bits_by_position(p_reg->otyper, static_cast<uint32_t>(p_cfg_->pin_num), true, static_cast<uint32_t>(p_cfg_->out_type));

                /* Configures alternate function */
                if (Cfg::Mode::alternate_function == p_cfg_->mode)
                {
                    /* TODO: Refactor */
                    const uint32_t tmp1 = static_cast<uint32_t>(p_cfg_->pin_num) / 8u;
                    const uint32_t tmp2 = static_cast<uint32_t>(p_cfg_->pin_num) % 8u;
                    utils::set_bits_by_position<uint32_t>(p_reg->afr[tmp1], 4u * tmp2, false, 0xFu);
                    utils::set_bits_by_position<uint32_t>(p_reg->afr[tmp1], 4u * tmp2, true, static_cast<uint32_t>(p_cfg_->alt_fun_mode));
                }
            }

            void Handle::toggle_pin() const
            {
                reg()->odr ^= 1u << static_cast<uint32_t>(p_cfg_->pin_num);
            }

            void Handle::deinit() const
            {
                rcc::reset_reg(p_cfg_->channel);
            }

            Pin_state Handle::read_pin() const
            {
                return utils::is_bit_set(reg()->idr, static_cast<uint32_t>(p_cfg_->pin_num)) ? Pin_state::set : Pin_state::reset;
            }

            uint16_t Handle::read_port() const
            {
                return static_cast<uint16_t>(reg()->idr);
            }

            void Handle::write_pin(Pin_state state) const
            {
                utils::set_bits_by_position(reg()->odr, static_cast<uint32_t>(p_cfg_->pin_num), Pin_state::set == state);
            }

            void Handle::write_port(uint16_t value) const
            {
                reg()->odr = value;
            }

            void Handle::set_irq_enabled(bool b_enabled) const
            {
                cortex::nvic::set_irq_enabled(Handle::irq_nums.at(static_cast<std::size_t>(p_cfg_->pin_num)), b_enabled);
            }

            void Handle::config_irq_priority(cortex::nvic::Irq_prio prio) const
            {
                cortex::nvic::set_irq_priority(Handle::irq_nums.at(static_cast<std::size_t>(p_cfg_->pin_num)), prio);
            }

            void Handle::handle_irq() const
            {
                const auto pin_number{static_cast<uint32_t>(p_cfg_->pin_num)};
                if (utils::is_bit_set(EXTI->pr, pin_number))
                {
                    utils::set_bits_by_position(EXTI->pr, pin_number, true);
                }
            }

            constexpr std::array<Reg *const, static_cast<std::size_t>(Cfg::Channel::total)> Handle::p_registers;
            constexpr std::array<cortex::nvic::Irq_num, static_cast<std::size_t>(Cfg::Pin_num::total)> Handle::irq_nums;

        } // namespace gpio

    } // namespace peripherals

} // namespace mcal
