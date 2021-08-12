#include "mcal/peripherals/rcc/inc/rcc.h"

#include <cstddef>
#include <array>

#include "utils.h"
#include "mcal/peripherals/gpio/inc/configuration.h"
#include "mcal/peripherals/spi/inc/cfg.h"
#include "mcal/inc/stm32f446xx.h"

namespace mcal
{
    namespace peripherals
    {
        namespace rcc
        {
            namespace apb
            {
                enum class Bus : size_t
                {
                    one,
                    two,
                    total,
                };

                enum class One_bits : uint32_t
                {
                    tim2,
                    tim3,
                    tim4,
                    tim5,
                    tim6,
                    tim7,
                    tim12,
                    tim13,
                    tim14,
                    _reserved1,
                    _reserved2,
                    wwdg,
                    _reserved3,
                    _reserved4,
                    spi2,
                    spi3,
                    spdifrx,
                    usart2,
                    usart3,
                    uart4,
                    uart5,
                    i2c1,
                    i2c2,
                    i2c3,
                    fmpi2c1,
                    can1,
                    can2,
                    cec,
                    pwr,
                    dac,
                };

                enum class Two_bits : uint32_t
                {
                    tim1,
                    tim8,
                    _reserved1,
                    _reserved2,
                    usart1,
                    usart6,
                    _reserved3,
                    _reserved4,
                    adc1,
                    adc2,
                    adc3,
                    sdio,
                    spi1,
                    spi4,
                    syscfg,
                    _reserved5,
                    tim9,
                    tim10,
                    tim11,
                    _reserved6,
                    _reserved7,
                    _reserved8,
                    sai1,
                    sai2
                };

            } // namespace apb

            namespace ahb
            {
                enum class Bus : size_t
                {
                    one,
                    two,
                    three,
                    total,
                };

                enum class One_bits : uint32_t
                {
                    gpioa,
                    gpiob,
                    gpioc,
                    gpiod,
                    gpioe,
                    gpiof,
                    gpiog,
                    gpioh,
                    _reserved1,
                    _reserved2,
                    _reserved3,
                    _reserved4,
                    crc,
                    _reserved5,
                    _reserved6,
                    _reserved7,
                    _reserved8,
                    _reserved9,
                    bkpsram,
                    _reserved10,
                    _reserved11,
                    dma1,
                    dma2,
                    _reserved12,
                    _reserved13,
                    _reserved14,
                    _reserved15,
                    _reserved16,
                    _reserved17,
                    otghs,
                    otghsulpi,
                };

            } // namespace ahb

            struct Reg
            {
                volatile uint32_t cr;
                volatile uint32_t pll_cfgr;
                volatile uint32_t cfgr;
                volatile uint32_t cir;
                volatile uint32_t ahbrstr[static_cast<size_t>(ahb::Bus::total)];
                uint32_t _reserved_1;
                volatile uint32_t apbrstr[static_cast<size_t>(apb::Bus::total)];
                uint32_t _reserved_2[2];
                volatile uint32_t ahbenr[static_cast<size_t>(ahb::Bus::total)];
                uint32_t _reserved_3;
                volatile uint32_t apbenr[static_cast<size_t>(apb::Bus::total)];
                uint32_t _reserved_4[2];
                volatile uint32_t ahblpenr[static_cast<size_t>(ahb::Bus::total)];
                uint32_t _reserved_5;
                volatile uint32_t apblpenr[static_cast<size_t>(apb::Bus::total)];
                uint32_t _reserved_6[2];
                volatile uint32_t bdcr;
                volatile uint32_t csr;
                uint32_t _reserved_7[2];
                volatile uint32_t sscgr;
                volatile uint32_t plli2scfgr;
                volatile uint32_t pllsaicfgr;
                volatile uint32_t dckcfgr;
                volatile uint32_t ckgatenr;
                volatile uint32_t dckcfgr2;
            };

#define RCC (reinterpret_cast<Reg *>(RCC_BASEADDR))

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
