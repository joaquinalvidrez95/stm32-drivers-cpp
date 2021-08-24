#include "mcal/peripherals/rcc/inc/rcc.h"

#include <cstddef>
#include <array>

#include "utils/inc/utils.h"
#include "mcal/peripherals/gpio/inc/ext.h"
#include "mcal/peripherals/spi/inc/ext.h"
#include "mcal/inc/stm32f446xx.h"
#include "mcal/peripherals/rcc/inc/ahb.h"
#include "mcal/peripherals/rcc/inc/aph.h"
#include "mcal/peripherals/rcc/inc/reg.h"

namespace mcal::peripherals::rcc
{
#define RCC (reinterpret_cast<reg *>(mcal::address::ahb1::rcc))

    namespace
    {
        constexpr std::array<uint32_t, static_cast<std::size_t>(
                                           peripherals::gpio::channel::total)>
            g_gpio_bit_positions{
                static_cast<uint32_t>(ahb::one_bits::gpioa),
                static_cast<uint32_t>(ahb::one_bits::gpiob),
                static_cast<uint32_t>(ahb::one_bits::gpioc),
                static_cast<uint32_t>(ahb::one_bits::gpiod),
                static_cast<uint32_t>(ahb::one_bits::gpioe),
                static_cast<uint32_t>(ahb::one_bits::gpiof),
                static_cast<uint32_t>(ahb::one_bits::gpiog),
                static_cast<uint32_t>(ahb::one_bits::gpioh),
            };

        constexpr std::array<std::pair<uint32_t, size_t>,
                             static_cast<std::size_t>(
                                 peripherals::spi::bus::total)>
            g_spi_mapping{
                std::pair{
                    static_cast<uint32_t>(apb::two_bits::spi1),
                    static_cast<size_t>(apb::bus::two),
                }, /* SPI1 */
                {
                    static_cast<uint32_t>(apb::one_bits::spi2),
                    static_cast<size_t>(apb::bus::one),
                }, /* SPI2 */
                {
                    static_cast<uint32_t>(apb::one_bits::spi3),
                    static_cast<size_t>(apb::bus::one),
                }, /* SPI3 */
                {
                    static_cast<uint32_t>(apb::two_bits::spi4),
                    static_cast<size_t>(apb::bus::two),
                }, /* SPI4 */
            };
    } // namespace

    void set_system_cfg_ctrl_clock_enabled(bool b_enabled)
    {
        const auto index{static_cast<size_t>(apb::bus::two)};
        RCC->apbenr[index] = utils::set_bits_by_position(
            RCC->apbenr[index],
            static_cast<uint32_t>(apb::two_bits::syscfg),
            b_enabled);
    }

    void set_clock_enabled(peripherals::gpio::channel channel, bool b_set)
    {
        const auto bit_position{
            g_gpio_bit_positions.at(static_cast<std::size_t>(channel))};
        const auto index{static_cast<size_t>(ahb::bus::one)};

        RCC->ahbenr[index] = utils::set_bits_by_position(RCC->ahbenr[index],
                                                         bit_position,
                                                         b_set);
    }

    void reset_reg(peripherals::gpio::channel channel)
    {
        const auto bit_position{
            g_gpio_bit_positions.at(static_cast<std::size_t>(channel))};
        const auto index{static_cast<size_t>(ahb::bus::one)};

        RCC->ahbrstr[index] = utils::set_bits_by_position(RCC->ahbrstr[index],
                                                          bit_position);
        RCC->ahbrstr[index] = utils::set_bits_by_position(RCC->ahbrstr[index],
                                                          bit_position,
                                                          false);
    }

    void set_clock_enabled(peripherals::spi::bus bus, bool b_set)
    {
        const auto [bit_position, apb_bus] =
            g_spi_mapping.at(static_cast<std::size_t>(bus));

        RCC->apbenr[apb_bus] = utils::set_bits_by_position(RCC->apbenr[apb_bus],
                                                           bit_position,
                                                           b_set);
    }

    void reset_reg(peripherals::spi::bus bus)
    {
        const auto [bit_position, apb_bus] =
            g_spi_mapping.at(static_cast<std::size_t>(bus));

        RCC->apbrstr[apb_bus] = utils::set_bits_by_position(
            RCC->apbrstr[apb_bus],
            bit_position);

        RCC->apbrstr[apb_bus] = utils::set_bits_by_position(
            RCC->apbrstr[apb_bus],
            bit_position,
            false);
    }
} // namespace mcal::peripherals::rcc
