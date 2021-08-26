#include "app/inc/cfg.h"

#if CFG_SAMPLE == CFG_SAMPLE_06_SPI_SEND
#include <array>
#include <cstddef>

#include "mcal/peripherals/spi/inc/ext.h"
#include "mcal/peripherals/gpio/inc/ext.h"
#include "utils/inc/utils.h"

namespace
{
    void init_gpios();
} // namespace

int main(void)
{
    init_gpios();

    mcal::peripherals::spi::cfg cfg{};
    cfg.ssm = mcal::peripherals::spi::sw_slave_management::enabled;
    cfg.ssi = mcal::peripherals::spi::internal_slave_select::enabled;
    const mcal::peripherals::spi::handle h_spi{cfg};

    constexpr std::array<char, 12> message{"Hello world"};
    std::array<std::byte, 12> buffer{};
    utils::to_bytes(message.cbegin(), message.cend(), buffer.begin());

    h_spi.set_state(mcal::peripherals::spi::state::enabled);
    h_spi.send(buffer.cbegin(), buffer.cend());
    h_spi.set_state(mcal::peripherals::spi::state::disabled);

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
        constexpr mcal::peripherals::gpio::cfg sck_cfg{
            mcal::peripherals::gpio::channel::a,
            mcal::peripherals::gpio::pin_num::p9,
            mcal::peripherals::gpio::mode::alternate_function,
            mcal::peripherals::gpio::out_type::push_pull,
            mcal::peripherals::gpio::pull_mode::none,
            mcal::peripherals::gpio::speed::low,
            mcal::peripherals::gpio::alternate_function::f5,
        };
        mcal::peripherals::gpio::handle h_sck{sck_cfg};

        // H26
        constexpr mcal::peripherals::gpio::cfg mosi_cfg{
            mcal::peripherals::gpio::channel::b,
            mcal::peripherals::gpio::pin_num::p15,
            mcal::peripherals::gpio::mode::alternate_function,
            mcal::peripherals::gpio::out_type::push_pull,
            mcal::peripherals::gpio::pull_mode::none,
            mcal::peripherals::gpio::speed::low,
            mcal::peripherals::gpio::alternate_function::f5,
        };
        mcal::peripherals::gpio::handle h_mosi{mosi_cfg};
    }
} // namespace

#endif
