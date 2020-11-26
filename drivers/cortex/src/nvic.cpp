/*
 * stm32f446xx_nvic_driver.c
 *
 *  Created on: Aug 29, 2020
 *      Author: joaquin
 */

#include "drivers/cortex/inc/nvic.h"

#include <stdbool.h>

#include "drivers/inc/stm32f446xx.h"

namespace drivers
{
    namespace cortex
    {
        namespace nvic
        {
            void set_irq_enabled(Irq_num irq_num, bool b_enabled)
            {
                constexpr uint32_t num_bits_per_register{32u};
                const uint32_t index{static_cast<uint32_t>(irq_num) / num_bits_per_register};
                const uint32_t bit_position{static_cast<uint32_t>(irq_num) % num_bits_per_register};
                volatile uint32_t *const reg{b_enabled ? NVIC_ISER0 : NVIC_ICER0};
                reg[index] |= 1u << bit_position;
            }

            void set_irq_priority(Irq_num irq_num, Irq_prio prio)
            {
                const uint32_t index{static_cast<uint32_t>(irq_num) / 4u};
                const uint32_t section{static_cast<uint32_t>(irq_num) % 4u};
                constexpr uint32_t num_prio_bits_implemented{4u};
                const uint32_t shift_amount{(8u * section) + (8u - num_prio_bits_implemented)};
                NVIC_PR_BASE_ADDR[index] |= static_cast<uint32_t>(prio) << shift_amount;
            }
        } // namespace nvic

    } // namespace cortex

} // namespace drivers
