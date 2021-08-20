/*
 * handle.h
 *
 *  Created on: Aug 11, 2021
 *      Author: joaquin
 */

#ifndef PERIPHERALS_SPI_INC_HANDLE_H_
#define PERIPHERALS_SPI_INC_HANDLE_H_

#include <cstddef>

#include "mcal/peripherals/spi/inc/reg.h"
#include "mcal/peripherals/spi/inc/cfg.h"

namespace mcal::peripherals::spi
{
    enum class Peripheral_state
    {
        disabled,
        enabled,
    };

    class Handle
    {
    public:
        Handle(const Cfg &cfg);

        ~Handle();

        void send(const std::byte *p_first, const std::byte *p_last) const;

        void set_peripheral_state(Peripheral_state state) const;

    private:
        void init_registers();

        void wait_till_not_busy() const;

        const Cfg &cfg_;
        Reg *const p_reg_;
    };
} // namespace mcal::peripherals::spi

#endif /* PERIPHERALS_SPI_INC_HANDLE_H_ */
