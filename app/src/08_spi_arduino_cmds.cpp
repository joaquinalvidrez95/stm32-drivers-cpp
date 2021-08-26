/**
 * @file 08_spi_arduino_cmds.cpp
 * @author Joaquin Alan Alvidrez Soto
 * @brief 
 * @date 2021-08-22
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "app/inc/cfg.h"
#if CFG_SAMPLE == CFG_SAMPLE_08_SPI_ARDUINO

#include <array>
#include <cstddef>
#include <cstdio>

#include "mcal/peripherals/spi/inc/ext.h"
#include "hal/nucleo/f446re/inc/spi.h"
#include "hal/nucleo/f446re/inc/button.h"
#include "hal/arduino/inc/spi.h"
#include "utils/inc/utils.h"

namespace
{
    void run_state_machine(const hal::arduino::spi &handle);
} // namespace

int main(void)
{
    const hal::nucleo::f446re::spi h_nucleo_spi{};
    const hal::nucleo::f446re::button h_button{};
    const hal::arduino::spi h_spi_arduino{h_nucleo_spi.handle()};

    for (;;)
    {
        h_button.wait_till_pressed();
        run_state_machine(h_spi_arduino);
    }
    return 0;
}

namespace
{
    void run_state_machine(const hal::arduino::spi &handle)
    {
        constexpr auto digital_pin{hal::arduino::digital_pin::p9};
        static auto curr_state{hal::arduino::spi::command::digital_write};

        switch (curr_state)
        {
        case hal::arduino::spi::command::digital_write:
            handle.write_pin(digital_pin,
                             mcal::peripherals::gpio::pin_state::set);
            curr_state = hal::arduino::spi::command::analog_read;
            break;

        case hal::arduino::spi::command::analog_read:
        {
            const auto pin{hal::arduino::analog_pin::p0};
            if (const auto read{handle.read_analog(pin)})
            {
                printf("Analog pin: %u, value: %u\n", static_cast<uint8_t>(pin),
                       std::to_integer<uint8_t>(read.value()));
            }
            curr_state = hal::arduino::spi::command::digital_read;
        }
        break;

        case hal::arduino::spi::command::digital_read:
        {
            if (const auto read{handle.read_digital(digital_pin)})
            {
                printf("Digital pin: %u, value: %u\n",
                       static_cast<uint8_t>(digital_pin),
                       static_cast<uint8_t>(read.value()));
            }
            curr_state = hal::arduino::spi::command::print;
        }
        break;

        case hal::arduino::spi::command::print:
        {
            constexpr std::string_view message{"Hello from Nucleo Board"};
            handle.print(message);
            curr_state = hal::arduino::spi::command::read_id;
        }
        break;

        case hal::arduino::spi::command::read_id:
        {
            std::array<std::byte, hal::arduino::spi::id_length + 1U>
                id{std::byte{0}};
            if (handle.read_id(id.begin(), id.end()))
            {
                printf("Arduino Board's ID: %s\n",
                       reinterpret_cast<const char *>(id.data()));
            }

            curr_state = hal::arduino::spi::command::digital_write;
        }
        break;

        default:
            break;
        }
    }

} // namespace

#endif
