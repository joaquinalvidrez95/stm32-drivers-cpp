/**
 * @file spi.cpp
 * @author Joaquin Alan Alvidrez Soto
 * @brief 
 * @date 2021-08-23
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "hal/arduino/inc/spi.h"

namespace hal::arduino
{
    spi::spi(const mcal::peripherals::spi::handle &handle) : handle_{handle}
    {
    }

    spi::~spi()
    {
    }

    mcal::peripherals::gpio::pin_state spi::read_digital(digital_pin pin)
    {
        // TODO: Implement
        return mcal::peripherals::gpio::pin_state::reset;
    }

    void spi::write_pin(digital_pin pin,
                        mcal::peripherals::gpio::pin_state state)
    {
    }

    void spi::print(std::string_view message)
    {
    }

    void spi::read_id(std::byte *p_first, std::byte *p_last)
    {
    }

} // namespace hal::arduino
