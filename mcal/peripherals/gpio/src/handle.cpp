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
#include "mcal/inc/exti.h"
#include "mcal/inc/syscfg.h"
#include "utils/inc/utils.h"
#include "mcal/peripherals/gpio/inc/gpio.h"

namespace mcal::peripherals::gpio
{
    namespace
    {
        constexpr std::array<cortex::nvic::irq_num,
                             static_cast<std::size_t>(pin_num::total)>
            g_irq_nums{
                cortex::nvic::irq_num::exti0,
                cortex::nvic::irq_num::exti1,
                cortex::nvic::irq_num::exti2,
                cortex::nvic::irq_num::exti3,
                cortex::nvic::irq_num::exti4,
                cortex::nvic::irq_num::exti9_5,
                cortex::nvic::irq_num::exti9_5,
                cortex::nvic::irq_num::exti9_5,
                cortex::nvic::irq_num::exti9_5,
                cortex::nvic::irq_num::exti9_5,
                cortex::nvic::irq_num::exti15_10,
                cortex::nvic::irq_num::exti15_10,
                cortex::nvic::irq_num::exti15_10,
                cortex::nvic::irq_num::exti15_10,
                cortex::nvic::irq_num::exti15_10,
                cortex::nvic::irq_num::exti15_10,
            };

        reg *map_reg(channel channel)
        {
            const std::array<reg *const,
                             static_cast<std::size_t>(channel::total)>
                p_registers{
                    reinterpret_cast<reg *>(address::ahb1::gpioa),
                    reinterpret_cast<reg *>(address::ahb1::gpiob),
                    reinterpret_cast<reg *>(address::ahb1::gpioc),
                    reinterpret_cast<reg *>(address::ahb1::gpiod),
                    reinterpret_cast<reg *>(address::ahb1::gpioe),
                    reinterpret_cast<reg *>(address::ahb1::gpiof),
                    reinterpret_cast<reg *>(address::ahb1::gpiog),
                    reinterpret_cast<reg *>(address::ahb1::gpioh),
                };
            return p_registers.at(static_cast<std::size_t>(channel));
        }
    } // namespace

    handle::handle(const cfg &cfg)
        : cfg_{cfg},
          p_reg_{map_reg(cfg_.channel)}
    {
        rcc::set_clock_enabled(cfg_.channel, true);
        init_registers();
    }

    handle::~handle()
    {
        deinit();
    }

    void handle::init_registers()
    {
        /* TODO: Create helper functions */

        /* TODO: Check if memset */
        /* Configures mode. */
        if (cfg_.mode <= mode::analog)
        {
            p_reg_->moder = utils::set_bits_by_position<uint32_t>(
                p_reg_->moder,
                2U * static_cast<uint32_t>(cfg_.pin_num),
                false,
                3U);
            p_reg_->moder = utils::set_bits_by_position(
                p_reg_->moder,
                2U * static_cast<uint32_t>(cfg_.pin_num),
                true,
                static_cast<uint32_t>(cfg_.mode));
        }
        else
        {
            /* TODO: Use utils */
            switch (cfg_.mode)
            {
            case mode::falling_transition_interrupt:
                EXTI->ftsr = utils::set_bits_by_position(
                    EXTI->ftsr,
                    static_cast<uint32_t>(cfg_.pin_num));
                EXTI->rtsr = utils::set_bits_by_position(
                    EXTI->rtsr,
                    static_cast<uint32_t>(cfg_.pin_num),
                    false);
                break;

            case mode::rising_transition_interrupt:
                EXTI->rtsr = utils::set_bits_by_position(
                    EXTI->rtsr,
                    static_cast<uint32_t>(cfg_.pin_num));
                EXTI->ftsr = utils::set_bits_by_position(
                    EXTI->ftsr,
                    static_cast<uint32_t>(cfg_.pin_num),
                    false);
                break;

            case mode::rising_falling_transition_interrupt:
                EXTI->rtsr = utils::set_bits_by_position(
                    EXTI->rtsr,
                    static_cast<uint32_t>(cfg_.pin_num));
                EXTI->ftsr = utils::set_bits_by_position(
                    EXTI->ftsr,
                    static_cast<uint32_t>(cfg_.pin_num));
                break;

            default:
                break;
            }

            /* Configures the GPIO port selection in SYSCFG_EXTICR */
            rcc::set_system_cfg_ctrl_clock_enabled(true);
            constexpr uint32_t num_bits_per_section{4U};
            const uint32_t idx = static_cast<uint32_t>(cfg_.pin_num) /
                                 num_bits_per_section;
            const uint32_t section = static_cast<uint32_t>(cfg_.pin_num) %
                                     num_bits_per_section;
            SYSCFG->exticr[idx] = static_cast<uint32_t>(cfg_.channel)
                                  << (section * num_bits_per_section);
            EXTI->imr = utils::set_bits_by_position(
                EXTI->imr,
                static_cast<uint32_t>(cfg_.pin_num));
        }

        /* Configures speed. */
        p_reg_->ospeeder = utils::set_bits_by_position<uint32_t>(
            p_reg_->ospeeder,
            2U * static_cast<uint32_t>(cfg_.pin_num),
            false,
            3U);
        p_reg_->ospeeder = utils::set_bits_by_position(
            p_reg_->ospeeder,
            2U * static_cast<uint32_t>(cfg_.pin_num),
            true,
            static_cast<uint32_t>(cfg_.speed));

        /* Configures pupd. */
        p_reg_->pupdr = utils::set_bits_by_position<uint32_t>(
            p_reg_->pupdr,
            2U * static_cast<uint32_t>(cfg_.pin_num),
            false,
            3U);
        p_reg_->pupdr = utils::set_bits_by_position<uint32_t>(
            p_reg_->pupdr,
            2U * static_cast<uint32_t>(cfg_.pin_num),
            false,
            static_cast<uint32_t>(cfg_.pull_mode));

        /* Configures opt type. */
        p_reg_->otyper = utils::set_bits_by_position(
            p_reg_->otyper,
            static_cast<uint32_t>(cfg_.pin_num),
            false);
        p_reg_->otyper = utils::set_bits_by_position(
            p_reg_->otyper,
            static_cast<uint32_t>(cfg_.pin_num),
            true,
            static_cast<uint32_t>(cfg_.out_type));

        /* Configures alternate function */
        if (mode::alternate_function == cfg_.mode)
        {
            /* TODO: Refactor */
            const uint32_t tmp1 = static_cast<uint32_t>(cfg_.pin_num) / 8U;
            const uint32_t tmp2 = static_cast<uint32_t>(cfg_.pin_num) % 8U;
            p_reg_->afr[tmp1] = utils::set_bits_by_position<uint32_t>(
                p_reg_->afr[tmp1],
                4U * tmp2,
                false,
                0xFU);
            p_reg_->afr[tmp1] = utils::set_bits_by_position<uint32_t>(
                p_reg_->afr[tmp1],
                4U * tmp2,
                true,
                static_cast<uint32_t>(cfg_.alt_fun_mode));
        }
    }

    void handle::toggle_pin() const
    {
        p_reg_->odr ^= 1U << static_cast<uint32_t>(cfg_.pin_num);
    }

    void handle::deinit() const
    {
        rcc::reset_reg(cfg_.channel);
    }

    pin_state handle::read_pin() const
    {
        return utils::is_bit_set(p_reg_->idr,
                                 static_cast<uint32_t>(cfg_.pin_num))
                   ? pin_state::set
                   : pin_state::reset;
    }

    uint16_t handle::read_port() const
    {
        return static_cast<uint16_t>(p_reg_->idr);
    }

    void handle::write_pin(pin_state state) const
    {
        p_reg_->odr = utils::set_bits_by_position(
            p_reg_->odr,
            static_cast<uint32_t>(cfg_.pin_num),
            pin_state::set == state);
    }

    void handle::write_port(uint16_t value) const
    {
        p_reg_->odr = value;
    }

    void handle::set_irq_enabled(bool b_enabled) const
    {
        cortex::nvic::set_irq_enabled(
            g_irq_nums.at(static_cast<std::size_t>(cfg_.pin_num)),
            b_enabled);
    }

    void handle::config_irq_priority(cortex::nvic::irq_prio prio) const
    {
        cortex::nvic::set_irq_priority(
            g_irq_nums.at(static_cast<std::size_t>(cfg_.pin_num)),
            prio);
    }

    void handle::handle_irq() const
    {
        const auto pin_number{static_cast<uint32_t>(cfg_.pin_num)};
        if (utils::is_bit_set(EXTI->pr, pin_number))
        {
            EXTI->pr = utils::set_bits_by_position(EXTI->pr, pin_number);
        }
    }
} // namespace mcal::peripherals::gpio
