/*
 * handle.cpp
 *
 *  Created on: Aug 11, 2021
 *      Author: joaquin
 */
#include "mcal/peripherals/spi/inc/handle.h"

#include <array>
#include <cstdint>

#include "mcal/peripherals/spi/inc/cfg.h"
#include "mcal/peripherals/spi/inc/reg.h"
#include "mcal/peripherals/rcc/inc/rcc.h"
#include "mcal/inc/stm32f446xx.h"
#include "utils.h"

namespace mcal::peripherals::spi
{
    namespace bitfield
    {
        enum class Cr1 : uint32_t
        {
            cpha,
            cpol,
            mstr,
            br0,
            br1,
            br2,
            spe,
            lsbfirst,
            ssi,
            ssm,
            rxonly,
            dff,
            crcnext,
            crcen,
            bidioe,
            bidimode,
        };

        enum class Cr2 : uint32_t
        {
            rxdmaen,
            txdmaen,
            ssoe,
            _reserved,
            frf,
            errie,
            rxneie,
            txeie,
        };

        enum class Sr : uint32_t
        {
            rxne,
            txe,
            chside,
            udr,
            crcerr,
            modf,
            ovr,
            bsy,
            fre,
        };

    } // namespace bitfield
    namespace
    {
        const std::array<Reg *const, static_cast<size_t>(Cfg::Bus::total)>
            gp_registers{
                reinterpret_cast<Reg *>(address::apb2::spi1),
                reinterpret_cast<Reg *>(address::apb1::spi2_i2s2),
                reinterpret_cast<Reg *>(address::apb1::spi3_i2s3),
                reinterpret_cast<Reg *>(address::apb2::spi4),
            };

        uint32_t calculate_cr1(const Cfg &cfg);
        uint32_t calculate_communication_mode(Cfg::Communication mode);
    }

    Handle::Handle(/* args */)
    {
    }

    Handle::~Handle()
    {
    }

    void Handle::init(const Cfg *p_cfg)
    {
        rcc::set_clock_enabled(p_cfg->bus, true);
        auto *const p_reg{gp_registers.at(static_cast<size_t>(p_cfg->bus))};

        p_reg->cr1 = calculate_cr1(*p_cfg);
#if 0
                p_cfg->baud_rate_ctrl
#endif
    }

    void Handle::send()
    {
    }

    namespace
    {
        uint32_t calculate_communication_mode(Cfg::Communication mode)
        {
            constexpr std::array<uint32_t,
                                 static_cast<size_t>(Cfg::Communication::total)>
                masks{
                    0U,
                    1U << static_cast<uint32_t>(bitfield::Cr1::bidimode),
                    1U << static_cast<uint32_t>(bitfield::Cr1::rxonly),
                };

            return masks.at(static_cast<size_t>(mode));
        }

        uint32_t calculate_cr1(const Cfg &cfg)
        {
            uint32_t cr1{0U};

            /* Baud rate */
            cr1 = utils::set_bits_by_position(
                cr1,
                static_cast<uint32_t>(bitfield::Cr1::br0),
                true,
                static_cast<uint32_t>(cfg.baud_rate_ctrl));

            /* Clock phase */
            cr1 = utils::set_bits_by_position(
                cr1,
                static_cast<uint32_t>(bitfield::Cr1::cpha),
                Cfg::Clock_phase::second_edge == cfg.clock.phase);

            /* Clock polarity */
            cr1 = utils::set_bits_by_position(
                cr1,
                static_cast<uint32_t>(bitfield::Cr1::cpol),
                Cfg::Clock_polarity::high == cfg.clock.polarity);

            cr1 |= calculate_communication_mode(cfg.communication);

            return cr1;
        }

    } // namespace

} // namespace mcal::peripherals::spi
