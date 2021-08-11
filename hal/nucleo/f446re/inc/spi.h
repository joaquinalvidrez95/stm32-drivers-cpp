/*
 * spi.h
 *
 *  Created on: Aug 10, 2021
 *      Author: joaquin
 */

#ifndef NUCLEO_F446RE_INC_SPI_H_
#define NUCLEO_F446RE_INC_SPI_H_

#include <cstddef>

namespace hal
{
    namespace nucleo
    {
        namespace f446re
        {
            class Spi
            {
            public:
                Spi();

                void init();

                void send(std::byte *first, std::byte *last);

                void send(const char *first, const char *last);
            };

        } // namespace f446re

    } // namespace nucleo

} // namespace hal

#endif /* NUCLEO_F446RE_INC_SPI_H_ */
