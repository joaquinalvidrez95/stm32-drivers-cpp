#include "drivers/peripherals/rcc/inc/rcc.h"

#include <cstddef>
#include <array>

#include "utils.h"
#include "drivers/inc/stm32f446xx.h"

namespace drivers
{
    namespace peripherals
    {
        namespace rcc
        {
            static constexpr std::array<uint32_t, static_cast<std::size_t>(gpio::Configuration::Channel::total)> gpio_bit_positions{
                0u,
                1u,
                2u,
                3u,
                4u,
                5u,
                6u,
                7u,
            };

            void set_gpio_clock_enabled(gpio::Configuration::Channel channel, bool b_set)
            {
                const auto bit_position{gpio_bit_positions.at(static_cast<std::size_t>(channel))};
                Utils::set_bit_by_position(RCC->ahbenr.one, bit_position, b_set);
            }

            void reset_gpio_reg(gpio::Configuration::Channel channel)
            {
                const auto bit_position{gpio_bit_positions.at(static_cast<std::size_t>(channel))};
                Utils::set_bit_by_position(RCC->ahbrstr.one, bit_position, true);
                Utils::set_bit_by_position(RCC->ahbrstr.one, bit_position, false);
            }
        } // namespace rcc

    } // namespace peripherals

} // namespace drivers
