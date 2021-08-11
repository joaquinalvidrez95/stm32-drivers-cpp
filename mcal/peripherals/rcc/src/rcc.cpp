#include "mcal/peripherals/rcc/inc/rcc.h"

#include <cstddef>
#include <array>

#include "utils.h"
#include "mcal/inc/stm32f446xx.h"

namespace mcal
{
    namespace peripherals
    {
        namespace rcc
        {
            namespace gpio
            {
                static constexpr std::array<uint32_t, static_cast<std::size_t>(
                                                          peripherals::gpio::Configuration::Channel::total)>
                    bit_positions{
                        0u,
                        1u,
                        2u,
                        3u,
                        4u,
                        5u,
                        6u,
                        7u,
                    };
                void set_clock_enabled(
                    peripherals::gpio::Configuration::Channel channel,
                    bool b_set)
                {
                    const auto bit_position{
                        bit_positions.at(static_cast<std::size_t>(channel))};
                    utils::set_bits_by_position(RCC->ahbenr.one,
                                                bit_position,
                                                b_set);
                }

                void reset_reg(peripherals::gpio::Configuration::Channel channel)
                {
                    const auto bit_position{
                        bit_positions.at(static_cast<std::size_t>(channel))};
                    utils::set_bits_by_position(RCC->ahbrstr.one,
                                                bit_position,
                                                true);
                    utils::set_bits_by_position(RCC->ahbrstr.one,
                                                bit_position,
                                                false);
                }
            } // namespace gpio

        } // namespace rcc

    } // namespace peripherals

} // namespace mcal
