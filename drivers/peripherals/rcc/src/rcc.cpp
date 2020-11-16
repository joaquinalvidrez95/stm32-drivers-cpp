#include "drivers/peripherals/rcc/inc/rcc.h"

#include <cstddef>

#include "utils.h"
#include "drivers/inc/stm32f446xx.h"

namespace drivers
{
    namespace peripherals
    {
        enum class Rcc_ahbenr : size_t
        {
            one = 0u,
            two = 1u,
            three = 2u,
            total
        };

        void Rcc::set_gpio_clock_enabled(gpio::Configuration::Channel channel, bool b_set)
        {
            constexpr uint8_t bit_positions[static_cast<std::size_t>(gpio::Configuration::Channel::total)] = {
                0u,
                1u,
                2u,
                3u,
                4u,
                5u,
                6u,
                7u,
            };
            const uint8_t bit_position{bit_positions[static_cast<std::size_t>(channel)]};

            /* TODO: Replace zero by AHB index enum */
            Utils::set_bit_by_position(RCC->AHBENR[static_cast<std::size_t>(Rcc_ahbenr::one)], bit_position, b_set);
        }

    } // namespace peripherals

} // namespace drivers
