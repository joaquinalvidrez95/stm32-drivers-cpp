#include "mcal/peripherals/rcc/inc/rcc.h"

#include <cstddef>
#include <array>

#include "utils.h"
#include "mcal/peripherals/gpio/inc/configuration.h"
#include "mcal/peripherals/spi/inc/cfg.h"
#include "mcal/inc/stm32f446xx.h"
#include "mcal/peripherals/rcc/inc/ahb.h"
#include "mcal/peripherals/rcc/inc/aph.h"
#include "mcal/peripherals/rcc/inc/reg.h"

namespace mcal
{
    namespace peripherals
    {
        namespace rcc
        {
            void set_system_cfg_ctrl_clock_enabled(bool b_enabled)
            {
                utils::set_bits_by_position(
                    RCC->apbenr[static_cast<size_t>(apb::Bus::two)],
                    static_cast<uint32_t>(apb::Two_bits::syscfg),
                    b_enabled);
            }

            static constexpr std::array<uint32_t, static_cast<std::size_t>(
                                                      peripherals::gpio::Cfg::Channel::total)>
                gpio_bit_positions{
                    static_cast<uint32_t>(ahb::One_bits::gpioa),
                    static_cast<uint32_t>(ahb::One_bits::gpiob),
                    static_cast<uint32_t>(ahb::One_bits::gpioc),
                    static_cast<uint32_t>(ahb::One_bits::gpiod),
                    static_cast<uint32_t>(ahb::One_bits::gpioe),
                    static_cast<uint32_t>(ahb::One_bits::gpiof),
                    static_cast<uint32_t>(ahb::One_bits::gpiog),
                    static_cast<uint32_t>(ahb::One_bits::gpioh),
                };

            void set_clock_enabled(peripherals::gpio::Cfg::Channel channel,
                                   bool b_set)
            {
                const auto bit_position{
                    gpio_bit_positions.at(static_cast<std::size_t>(channel))};
                utils::set_bits_by_position(
                    RCC->ahbenr[static_cast<size_t>(ahb::Bus::one)],
                    bit_position,
                    b_set);
            }

            void reset_reg(peripherals::gpio::Cfg::Channel channel)
            {
                const auto bit_position{
                    gpio_bit_positions.at(static_cast<std::size_t>(channel))};
                utils::set_bits_by_position(
                    RCC->ahbrstr[static_cast<size_t>(ahb::Bus::one)],
                    bit_position,
                    true);
                utils::set_bits_by_position(
                    RCC->ahbrstr[static_cast<size_t>(ahb::Bus::one)],
                    bit_position,
                    false);
            }

            void set_clock_enabled(peripherals::spi::Cfg::Bus bus, bool b_set)
            {
                constexpr std::array<std::pair<uint32_t, size_t>,
                                     static_cast<std::size_t>(
                                         peripherals::spi::Cfg::Bus::total)>
                    parameters{
                        std::pair{
                            static_cast<uint32_t>(apb::Two_bits::spi1),
                            static_cast<size_t>(apb::Bus::two),
                        }, /* SPI1 */
                        {
                            static_cast<uint32_t>(apb::One_bits::spi2),
                            static_cast<size_t>(apb::Bus::one),
                        }, /* SPI2 */
                        {
                            static_cast<uint32_t>(apb::One_bits::spi3),
                            static_cast<size_t>(apb::Bus::one),
                        }, /* SPI3 */
                        {
                            static_cast<uint32_t>(apb::Two_bits::spi4),
                            static_cast<size_t>(apb::Bus::two),
                        }, /* SPI4 */
                    };
                const auto [bit_position, apb_bus] =
                    parameters.at(static_cast<std::size_t>(bus));

                utils::set_bits_by_position(RCC->apbenr[apb_bus],
                                            bit_position,
                                            b_set);
            }

            void reset_reg(peripherals::spi::Cfg::Bus bus) {}
        } // namespace rcc

    } // namespace peripherals

} // namespace mcal
