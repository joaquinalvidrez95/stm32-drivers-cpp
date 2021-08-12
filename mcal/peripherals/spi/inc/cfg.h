/*
 * cfg.h
 *
 *  Created on: Aug 11, 2021
 *      Author: joaquin
 */

#ifndef PERIPHERALS_SPI_INC_CFG_H_
#define PERIPHERALS_SPI_INC_CFG_H_

#include <cstdint>

namespace mcal
{
    namespace peripherals
    {
        namespace spi
        {
            struct Configuration
            {
                enum class Device_mode : uint32_t
                {
                    slave,
                    master,
                };

                enum class Communication : uint32_t
                {
                    full_duplex,
                    half_duplex,
                    simplex,
                };

                enum class Baud_rate_ctrl : uint32_t
                {
                    div_2,
                    div_4,
                    div_8,
                    div_16,
                    div_32,
                    div_64,
                    div_128,
                    div_256,
                };

                enum class Data_frame_format : uint32_t
                {
                    bit_8,
                    bit_16,
                };

                /**
                * @brief The CPOL (clock polarity) bit controls the idle state 
                * value of the clock when no data is being transferred.
                */
                enum class Clock_polarity : uint32_t
                {
                    /** CK to 0 when idle  */
                    low,
                    /** CK to 1 when idle  */
                    high
                };

                enum class Clock_phase : uint32_t
                {
                    /**
                     * @brief The first clock transition is the first data 
                     * capture edge                    
                     */
                    first_edge,

                    /**
                     * @brief The second clock transition is the first data 
                     * capture edge
                     */
                    second_edge
                };

                enum class Bus : uint32_t
                {
                    one,
                    two,
                    three,
                    four,
                    total
                };
            };

        } // namespace spi

    } // namespace peripherals

} // namespace mcal

#endif /* PERIPHERALS_SPI_INC_CFG_H_ */
