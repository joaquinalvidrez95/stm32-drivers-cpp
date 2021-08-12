/*
 * spi.h
 *
 *  Created on: Aug 10, 2021
 *      Author: joaquin
 */

#ifndef NUCLEO_F446RE_INC_SPI_H_
#define NUCLEO_F446RE_INC_SPI_H_

#include <cstddef>

namespace hal::nucleo::f446re
{
    class Spi
    {
    public:
        Spi();

        void init();

        void send(std::byte *first, std::byte *last);

        void send(const char *first, const char *last);
    };
} // namespace hal::nucleo::f446re

#endif /* NUCLEO_F446RE_INC_SPI_H_ */
