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
    enum class state
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

        void read(std::byte *p_first, std::byte *p_last) const;

        /**
         * @brief Sends a dummy byte to move shift register.
         * 
         */
        void move_shift_register() const;

        std::byte read_byte() const;

        void clear_rx_buffer_not_empty_flag() const;

        void set_state(state state) const;

    private:
        // TODO: Move to unnamed namespace
        void init_registers() const;

        void wait_till_not_busy() const;

        void wait_till_tx_buffer_empty() const;

        void wait_till_rx_buffer_not_empty() const;

        const cfg &cfg_;
        reg *const p_reg_;
    };
} // namespace mcal::peripherals::spi

#endif /* PERIPHERALS_SPI_INC_HANDLE_H_ */
