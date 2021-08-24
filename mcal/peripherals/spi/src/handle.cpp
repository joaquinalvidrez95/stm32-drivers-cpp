/*
 * handle.cpp
 *
 *  Created on: Aug 11, 2021
 *      Author: joaquin
 */
#include "mcal/peripherals/spi/inc/handle.h"

#include <array>
#include <cstdint>
#include <cstddef>

#include "mcal/peripherals/spi/inc/cfg.h"
#include "mcal/peripherals/spi/inc/reg.h"
#include "mcal/peripherals/rcc/inc/rcc.h"
#include "mcal/inc/stm32f446xx.h"
#include "utils/inc/utils.h"

namespace mcal::peripherals::spi
{
    namespace
    {
        reg *get_reg(bus bus);

        uint32_t calculate_cr1(const cfg &cfg);
        uint32_t calculate_cr2(const cfg &cfg);
        uint32_t calculate_communication_mode(communication mode);
    }

    handle::handle(const cfg &cfg)
        : cfg_{cfg},
          p_reg_{get_reg(cfg.bus)}
    {
        rcc::set_clock_enabled(cfg.bus, true);
        init_registers();
    }

    handle::~handle()
    {
        rcc::reset_reg(cfg_.bus);
    }

    void handle::init_registers() const
    {
        p_reg_->cr1 = calculate_cr1(cfg_);
        p_reg_->cr2 = calculate_cr2(cfg_);
    }

    // TODO: Check if it can be a template
    void handle::send(const std::byte *p_first, const std::byte *p_last) const
    {
        const auto [increment, offset]{data_frame_format::bit_16 ==
                                               cfg_.data_frame_format
                                           ? std::pair{2U, 1U}
                                           : std::pair{1U, 0U}};

        for (auto it = p_first; (it + offset) < p_last; it += increment)
        {
            wait_till_tx_buffer_empty();

            if (data_frame_format::bit_8 == cfg_.data_frame_format)
            {
                p_reg_->dr = std::to_integer<uint32_t>(*it);
            }
            else
            {
                const auto lsb{std::to_integer<uint32_t>(it[0U])};
                const auto msb{std::to_integer<uint32_t>(it[1U]) << 8U};
                p_reg_->dr = msb | lsb;
            }
        }
    }

    void handle::send(std::byte data) const
    {
        wait_till_tx_buffer_empty();
        p_reg_->dr = std::to_integer<uint32_t>(data);
    }

    void handle::send_dummy() const
    {
        send(std::byte{0});
    }

    void handle::set_peripheral_state(peripheral_state state) const
    {
        if (peripheral_state::disabled == state)
        {
            wait_till_not_busy();
        }

        p_reg_->cr1 = utils::set_bits_by_position(
            p_reg_->cr1, static_cast<uint32_t>(bitfield::cr1::spe),
            peripheral_state::enabled == state);
    }

    void handle::wait_till_not_busy() const
    {
        while (utils::is_bit_set(p_reg_->sr,
                                 static_cast<uint32_t>(bitfield::sr::bsy)))
        {
        }
    }

    void handle::wait_till_tx_buffer_empty() const
    {
        while (!utils::is_bit_set(p_reg_->sr,
                                  static_cast<uint32_t>(bitfield::sr::txe)))
        {
        }
    }

    void handle::wait_till_rx_buffer_not_empty() const
    {
        while (!utils::is_bit_set(p_reg_->sr,
                                  static_cast<uint32_t>(bitfield::sr::rxne)))
        {
        }
    }

    namespace
    {
        reg *get_reg(bus bus)
        {
            const std::array<reg *const, static_cast<size_t>(bus::total)>
                p_registers{
                    reinterpret_cast<reg *>(address::apb2::spi1),
                    reinterpret_cast<reg *>(address::apb1::spi2_i2s2),
                    reinterpret_cast<reg *>(address::apb1::spi3_i2s3),
                    reinterpret_cast<reg *>(address::apb2::spi4),
                };
            return p_registers.at(static_cast<size_t>(bus));
        }

        uint32_t calculate_communication_mode(communication mode)
        {
            constexpr std::array<uint32_t,
                                 static_cast<size_t>(communication::total)>
                masks{
                    0U,
                    1U << static_cast<uint32_t>(bitfield::cr1::bidimode),
                    1U << static_cast<uint32_t>(bitfield::cr1::rxonly),
                };

            return masks.at(static_cast<size_t>(mode));
        }

        uint32_t calculate_cr1(const cfg &cfg)
        {
            uint32_t cr1{0U};

            /* Baud rate */
            cr1 = utils::set_bits_by_position(
                cr1, static_cast<uint32_t>(bitfield::cr1::br0), true,
                static_cast<uint32_t>(cfg.baud_rate_ctrl));

            /* Clock phase */
            cr1 = utils::set_bits_by_position(
                cr1, static_cast<uint32_t>(bitfield::cr1::cpha),
                clock_phase::second_edge == cfg.clock.phase);

            /* Clock polarity */
            cr1 = utils::set_bits_by_position(
                cr1, static_cast<uint32_t>(bitfield::cr1::cpol),
                clock_polarity::high == cfg.clock.polarity);

            cr1 |= calculate_communication_mode(cfg.communication);

            cr1 = utils::set_bits_by_position(
                cr1, static_cast<uint32_t>(bitfield::cr1::lsbfirst),
                frame_format::lsb == cfg.frame_format);

            cr1 = utils::set_bits_by_position(
                cr1, static_cast<uint32_t>(bitfield::cr1::ssm),
                sw_slave_management::enabled == cfg.ssm);

            cr1 = utils::set_bits_by_position(
                cr1, static_cast<uint32_t>(bitfield::cr1::ssi),
                internal_slave_select::enabled == cfg.ssi);

            cr1 = utils::set_bits_by_position(
                cr1, static_cast<uint32_t>(bitfield::cr1::mstr),
                device_mode::master == cfg.dev_mode);

            cr1 = utils::set_bits_by_position(
                cr1, static_cast<uint32_t>(bitfield::cr1::dff),
                data_frame_format::bit_16 == cfg.data_frame_format);
            return cr1;
        }

        uint32_t calculate_cr2(const cfg &cfg)
        {
            uint32_t cr2{0U};

            cr2 = utils::set_bits_by_position(
                cr2, static_cast<uint32_t>(bitfield::cr2::ssoe),
                ss_out_enable::enabled == cfg.ssoe);

            return cr2;
        }

    } // namespace

} // namespace mcal::peripherals::spi
