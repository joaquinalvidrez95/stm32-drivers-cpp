/**
 * @file cfg.h
 * @author Joaquin Alan Alvidrez Soto
 * @brief 
 * @date 2021-08-16
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef PERIPHERALS_SPI_INC_CFG_H_
#define PERIPHERALS_SPI_INC_CFG_H_

#include <cstdint>

namespace mcal::peripherals::spi
{
    struct Cfg
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
            total,
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
             * @brief The first clock transition is the first data capture edge.                
             */
            first_edge,

            /**
             * @brief The second clock transition is the first data capture 
             * edge.
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

        Communication communication;
        Bus bus;
        Data_frame_format data_frame_format;
        Baud_rate_ctrl baud_rate_ctrl;
        struct
        {
            Clock_polarity polarity;
            Clock_phase phase;
        } clock;
    };

} // namespace mcal::peripherals::spi

#endif /* PERIPHERALS_SPI_INC_CFG_H_ */
