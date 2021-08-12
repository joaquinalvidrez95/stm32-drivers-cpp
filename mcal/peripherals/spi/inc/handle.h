/*
 * handle.h
 *
 *  Created on: Aug 11, 2021
 *      Author: joaquin
 */

#ifndef PERIPHERALS_SPI_INC_HANDLE_H_
#define PERIPHERALS_SPI_INC_HANDLE_H_

#include "mcal/peripherals/spi/inc/cfg.h"

namespace mcal::peripherals::spi
{
    class Handle
    {
    public:
        Handle(/* args */);
        ~Handle();
        void init(const Cfg *p_cfg);

    private:
        /* data */
    };
} // namespace mcal::peripherals::spi

#endif /* PERIPHERALS_SPI_INC_HANDLE_H_ */
