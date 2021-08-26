/**
 * @file spi.h
 * @author Joaquin Alan Alvidrez Soto
 * @brief 
 * @date 2021-08-23
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef HAL_ARDUINO_INC_SPI_H
#define HAL_ARDUINO_INC_SPI_H

#include <cstddef>
#include <string_view>
#include <optional>

#include "mcal/peripherals/spi/inc/ext.h"
#include "mcal/peripherals/gpio/inc/ext.h"
#include "hal/arduino/inc/arduino.h"

namespace hal::arduino
{
    class spi
    {
    public:
        spi(const mcal::peripherals::spi::handle &handle);

        std::optional<mcal::peripherals::gpio::pin_state> read_digital(
            digital_pin pin);

        void write_pin(digital_pin pin,
                       mcal::peripherals::gpio::pin_state state);

        std::optional<std::byte> read_analog(analog_pin pin);

        void print(std::string_view message);

        void read_id(std::byte *p_first, std::byte *p_last);

    private:
        const mcal::peripherals::spi::handle &handle_;
    };

} // namespace hal::arduino

#endif // HAL_ARDUINO_INC_SPI_H
