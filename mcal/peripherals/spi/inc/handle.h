/*
 * handle.h
 *
 *  Created on: Aug 11, 2021
 *      Author: joaquin
 */

#ifndef PERIPHERALS_SPI_INC_HANDLE_H_
#define PERIPHERALS_SPI_INC_HANDLE_H_

#include "mcal/peripherals/spi/inc/cfg.h"
#include <cstddef>

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
        // TODO: Check if needed
        void init(const Cfg *p_cfg);

        void send(const std::byte *p_first, const std::byte *p_last) const;

        void set_peripheral_state(Peripheral_state state) const;

    private:
        const Cfg &cfg_;
#if 0
        const Cfg *p_cfg_{nullptr};
#endif
    };
} // namespace mcal::peripherals::spi

#endif /* PERIPHERALS_SPI_INC_HANDLE_H_ */
