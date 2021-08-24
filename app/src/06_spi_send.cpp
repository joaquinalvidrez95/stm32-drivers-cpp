#include <array>
#include <cstddef>

#include "mcal/peripherals/spi/inc/ext.h"
#include "mcal/peripherals/gpio/inc/ext.h"
#include "app/inc/cfg.h"
#include "utils/inc/utils.h"

#if CFG_SAMPLE == CFG_SAMPLE_06_SPI_SEND

namespace
{
    void init_gpios();
} // namespace

int main(void)
{
    init_gpios();

    mcal::peripherals::spi::Cfg cfg{};
    cfg.ssm = mcal::peripherals::spi::Cfg::Sw_slave_management::enabled;
    cfg.ssi = mcal::peripherals::spi::Cfg::Internal_slave_select::enabled;
    const mcal::peripherals::spi::handle h_spi{cfg};

    constexpr std::array<char, 12> message{"Hello world"};
    std::array<std::byte, 12> buffer{};
    utils::to_bytes(message.cbegin(), message.cend(), buffer.begin());

    h_spi.set_peripheral_state(
        mcal::peripherals::spi::peripheral_state::enabled);
    h_spi.send(buffer.cbegin(), buffer.cend());
    h_spi.set_peripheral_state(
        mcal::peripherals::spi::peripheral_state::disabled);

    for (;;)
    {
    }
    return 0;
}

namespace
{
    void init_gpios()
    {
        // D8
        constexpr mcal::peripherals::gpio::Cfg sck_cfg{
            mcal::peripherals::gpio::Cfg::Channel::a,
            mcal::peripherals::gpio::Cfg::Pin_num::p9,
            mcal::peripherals::gpio::Cfg::Mode::alternate_function,
            mcal::peripherals::gpio::Cfg::Out_type::push_pull,
            mcal::peripherals::gpio::Cfg::Pull_mode::none,
            mcal::peripherals::gpio::Cfg::Speed::low,
            mcal::peripherals::gpio::Cfg::Alternate_function::f5,
        };
        mcal::peripherals::gpio::handle h_sck{sck_cfg};

        // H26
        constexpr mcal::peripherals::gpio::Cfg mosi_cfg{
            mcal::peripherals::gpio::Cfg::Channel::b,
            mcal::peripherals::gpio::Cfg::Pin_num::p15,
            mcal::peripherals::gpio::Cfg::Mode::alternate_function,
            mcal::peripherals::gpio::Cfg::Out_type::push_pull,
            mcal::peripherals::gpio::Cfg::Pull_mode::none,
            mcal::peripherals::gpio::Cfg::Speed::low,
            mcal::peripherals::gpio::Cfg::Alternate_function::f5,
        };
        mcal::peripherals::gpio::handle h_mosi{mosi_cfg};
    }
} // namespace

#endif
