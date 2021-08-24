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
    enum class peripheral_state
    {
        disabled,
        enabled,
    };

    class handle
    {
    public:
        handle(const cfg &cfg);

        ~handle();

        void send(const std::byte *p_first, const std::byte *p_last) const;

        void send(std::byte data) const;

        void send_dummy() const;

        void set_peripheral_state(peripheral_state state) const;

    private:
        void init_registers() const;

        void wait_till_not_busy() const;

        void wait_till_tx_buffer_empty() const;

        void wait_till_rx_buffer_not_empty() const;

        const cfg &cfg_;
        reg *const p_reg_;
    };
} // namespace mcal::peripherals::spi

#endif /* PERIPHERALS_SPI_INC_HANDLE_H_ */
