/**
 * @file 07_spi_tx_only_arduino.cpp
 * @author Joaquin Alan Alvidrez Soto
 * @brief 
 * @date 2021-08-19
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <array>
#include <cstddef>

#include "mcal/peripherals/spi/inc/ext.h"
#include "hal/nucleo/f446re/inc/spi.h"
#include "hal/nucleo/f446re/inc/button.h"
#include "app/inc/cfg.h"
#include "utils/inc/utils.h"

#if CFG_SAMPLE == CFG_SAMPLE_07_SPI_TX_ONLY_ARDUINO

int main(void)
{
    constexpr std::array<char, 18U> message{"Hello Arduino Uno"};
    std::array<std::byte, message.size()> buffer{};
    utils::to_bytes(message.cbegin(), message.cend(), buffer.begin());

    const hal::nucleo::f446re::spi h_spi{};
    const hal::nucleo::f446re::button h_button{};

    for (;;)
    {
        h_button.wait_till_pressed();
        h_spi.handle().set_state(mcal::peripherals::spi::state::enabled);

        h_spi.handle().send(std::byte{message.size()});
        h_spi.handle().send(buffer.cbegin(), buffer.cend());
        h_spi.handle().set_state(mcal::peripherals::spi::state::disabled);
    }
    return 0;
}

#endif
