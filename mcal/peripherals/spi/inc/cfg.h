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
#include <cstddef>

namespace mcal::peripherals::spi
{
    struct Cfg
    {
        enum class Device_mode
        {
            slave,
            master,
        };

        enum class Communication
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

        enum class Data_frame_format
        {
            bit_8,
            bit_16,
        };

        /**
        * @brief The CPOL (clock polarity) bit controls the idle state 
        * value of the clock when no data is being transferred.
        */
        enum class Clock_polarity
        {
            /** CK to 0 when idle  */
            low,
            /** CK to 1 when idle  */
            high
        };

        enum class Clock_phase
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

        enum class Bus : size_t
        {
            one,
            two,
            three,
            four,
            total
        };

        enum class Frame_format
        {
            /* MSB transmitted first. */
            msb,
            /* LSB transmitted first. */
            lsb,
        };

        enum class Sw_slave_management
        {
            /* Software Slave Management disabled. */
            disabled,
            /* Software Slave Management enabled. */
            enabled,
        };

        enum class Ss_out_enable
        {
            /* SS output is disabled in master mode and the cell can work in 
            multimaster configuration. */
            disabled,
            /* SS output is enabled in master mode and when the cell is enabled.
            The cell cannot work in a multimaster environment. */
            enabled,
        };

        enum class Internal_slave_select
        {
            disabled,
            enabled,
        };

        Bus bus;
        Baud_rate_ctrl baud_rate_ctrl;
        Device_mode dev_mode{Device_mode::master};
        Communication communication{Communication::full_duplex};
        Data_frame_format data_frame_format{Data_frame_format::bit_8};
        struct
        {
            Clock_polarity polarity{Clock_polarity::low};
            Clock_phase phase{Clock_phase::first_edge};
        } clock;
        Frame_format frame_format{Frame_format::msb};
        Ss_out_enable ss_out{Ss_out_enable::disabled};
        Sw_slave_management ssm{Sw_slave_management::disabled};
        Internal_slave_select ssi{Internal_slave_select::disabled};
    };

} // namespace mcal::peripherals::spi

#endif /* PERIPHERALS_SPI_INC_CFG_H_ */
