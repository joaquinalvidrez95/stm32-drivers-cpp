#include <array>
#include <cstddef>

#include "hal/nucleo/f446re/inc/spi.h"
#include "cfg.h"
#include "utils.h"

#if CFG_SAMPLE == CFG_SAMPLE_06_SPI_SEND

int main(void)
{
    hal::nucleo::f446re::Spi spi{};
    spi.init();
    std::array<char, 12> message{"Hello world"};
    std::array<std::byte, 12> buffer{};

    utils::to_bytes(message.cbegin(), message.cend(), buffer.begin());

    spi.handle().set_peripheral_state(
        mcal::peripherals::spi::Peripheral_state::enabled);
    spi.handle().send(buffer.cbegin(), buffer.cend());
    spi.handle().set_peripheral_state(
        mcal::peripherals::spi::Peripheral_state::disabled);

    for (;;)
    {
    }
    return 0;
}

#endif
