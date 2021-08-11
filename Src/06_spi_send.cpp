#include <array>

#include "hal/nucleo/f446re/inc/spi.h"
#include "cfg.h"

#if CFG_SAMPLE == CFG_SAMPLE_06_SPI_SEND

int main(void)
{
    hal::nucleo::f446re::Spi spi{};
    spi.init();
    std::array<char, 12> message{"Hello world"};
    spi.send(message.cbegin(), message.cend());

    for (;;)
    {
    }
    return 0;
}


#endif
