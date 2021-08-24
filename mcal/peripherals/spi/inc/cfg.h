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

    enum class device_mode
    {
        slave,
        master,
    };

    enum class communication
    {
        full_duplex,
        half_duplex,
        simplex,
        total,
    };

    enum class baud_rate_ctrl : uint32_t
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

    enum class data_frame_format
    {
        bit_8,
        bit_16,
    };

    /**
        * @brief The CPOL (clock polarity) bit controls the idle state 
        * value of the clock when no data is being transferred.
        */
    enum class clock_polarity
    {
        /** CK to 0 when idle  */
        low,
        /** CK to 1 when idle  */
        high
    };

    enum class clock_phase
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

    enum class bus : size_t
    {
        one,
        two,
        three,
        four,
        total
    };

    enum class frame_format
    {
        /* MSB transmitted first. */
        msb,
        /* LSB transmitted first. */
        lsb,
    };

    enum class sw_slave_management
    {
        /* Software Slave Management disabled. */
        disabled,
        /* Software Slave Management enabled. */
        enabled,
    };

    enum class ss_out_enable
    {
        /* SS output is disabled in master mode and the cell can work in 
            multimaster configuration. */
        disabled,
        /* SS output is enabled in master mode and when the cell is enabled.
            The cell cannot work in a multimaster environment. */
        enabled,
    };

    enum class internal_slave_select
    {
        disabled,
        enabled,
    };

    struct cfg
    {
        spi::bus bus{bus::two};
        spi::baud_rate_ctrl baud_rate_ctrl{baud_rate_ctrl::div_8};
        device_mode dev_mode{device_mode::master};
        spi::communication communication{communication::full_duplex};
        spi::data_frame_format data_frame_format{data_frame_format::bit_8};
        struct
        {
            clock_polarity polarity{clock_polarity::low};
            clock_phase phase{clock_phase::first_edge};
        } clock;
        spi::frame_format frame_format{frame_format::msb};
        ss_out_enable ssoe{ss_out_enable::enabled};
        sw_slave_management ssm{sw_slave_management::disabled};
        internal_slave_select ssi{internal_slave_select::disabled};
    };

} // namespace mcal::peripherals::spi

#endif /* PERIPHERALS_SPI_INC_CFG_H_ */
