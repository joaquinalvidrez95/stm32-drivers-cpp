/*
 * stm32f446xx_nvic_driver.c
 *
 *  Created on: Aug 29, 2020
 *      Author: joaquin
 */

#include "mcal/cortex/inc/nvic.h"

#include <stdbool.h>

#include "mcal/inc/stm32f446xx.h"

namespace mcal::cortex::nvic
{
    // TODO: Use utils
    void set_irq_enabled(irq_num num, bool b_enabled)
    {
        constexpr uint32_t num_bits_per_register{32U};
        const uint32_t index{static_cast<uint32_t>(num) / num_bits_per_register};
        const uint32_t bit_position{
            static_cast<uint32_t>(num) % num_bits_per_register};
        volatile uint32_t *const reg{b_enabled ? NVIC_ISER0 : NVIC_ICER0};
        reg[index] |= 1U << bit_position;
    }

    void set_irq_priority(irq_num num, irq_prio prio)
    {
        const uint32_t index{static_cast<uint32_t>(num) / 4U};
        const uint32_t section{static_cast<uint32_t>(num) % 4U};
        constexpr uint32_t num_prio_bits_implemented{4U};
        const uint32_t shift_amount{(8U * section) +
                                    (8U - num_prio_bits_implemented)};
        NVIC_PR_BASE_ADDR[index] |= static_cast<uint32_t>(prio) << shift_amount;
    }
} // namespace mcal::cortex::nvic
