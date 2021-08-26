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

#include <cstddef>
#include <optional>

#include "utils/inc/utils.h"

namespace hal::arduino
{
    enum class response : std::underlying_type_t<std::byte>
    {
        nack = 0xA5U,
        ack = 0xF5U,
    };

    namespace
    {
        bool is_response_ack(const mcal::peripherals::spi::handle &h_spi);
        bool send_cmd(const mcal::peripherals::spi::handle &h_spi,
                      spi::command cmd);
    } // namespace

    spi::spi(const mcal::peripherals::spi::handle &handle) : handle_{handle}
    {
    }

    std::optional<mcal::peripherals::gpio::pin_state> spi::read_digital(
        digital_pin pin) const
    {
        handle_.set_state(mcal::peripherals::spi::state::enabled);

        std::optional<mcal::peripherals::gpio::pin_state> out{};

        if (send_cmd(handle_, command::digital_read))
        {
            handle_.send(static_cast<std::byte>(pin));
            handle_.clear_rx_buffer_not_empty_flag();
            utils::delay();
            handle_.move_shift_register();
            const auto read{handle_.read_byte()};
            out = read == static_cast<std::byte>(
                              mcal::peripherals::gpio::pin_state::set)
                      ? mcal::peripherals::gpio::pin_state::set
                      : mcal::peripherals::gpio::pin_state::reset;
        }

        handle_.set_state(mcal::peripherals::spi::state::disabled);

        return out;
    }

    void spi::write_pin(digital_pin pin,
                        mcal::peripherals::gpio::pin_state state) const
    {
        handle_.set_state(mcal::peripherals::spi::state::enabled);

        if (send_cmd(handle_, command::digital_write))
        {
            const std::array<std::byte, 2U> msg{
                static_cast<std::byte>(pin),
                static_cast<std::byte>(state),
            };
            handle_.send(msg.cbegin(), msg.cend());
            // TODO: Is clearing RXNE needed?
        }

        handle_.set_state(mcal::peripherals::spi::state::disabled);
    }

    std::optional<std::byte> spi::read_analog(analog_pin pin) const
    {
        handle_.set_state(mcal::peripherals::spi::state::enabled);

        std::optional<std::byte> out{};

        if (send_cmd(handle_, command::analog_read))
        {
            handle_.send(static_cast<std::byte>(pin));
            handle_.clear_rx_buffer_not_empty_flag();
            utils::delay();
            handle_.move_shift_register();
            out = handle_.read_byte();
        }

        handle_.set_state(mcal::peripherals::spi::state::disabled);

        return out;
    }

    void spi::print(std::string_view message) const
    {
        handle_.set_state(mcal::peripherals::spi::state::enabled);
        if (send_cmd(handle_, command::print))
        {
            handle_.send(static_cast<std::byte>(message.size()));
            // TODO: Is it necessary to clear RXNE?
            handle_.send(reinterpret_cast<const std::byte *>(message.cbegin()),
                         reinterpret_cast<const std::byte *>(message.cend()));
            handle_.clear_rx_buffer_not_empty_flag();
        }
        handle_.set_state(mcal::peripherals::spi::state::disabled);
    }

    bool spi::read_id(std::byte *p_first, std::byte *p_last) const
    {
        handle_.set_state(mcal::peripherals::spi::state::enabled);

        bool ok{false};
        if (send_cmd(handle_, command::read_id))
        {
            ok = true;
            handle_.move_shift_register();
            handle_.read(p_first, p_last);
        }
        handle_.set_state(mcal::peripherals::spi::state::disabled);

        return ok;
    }

    namespace
    {
        bool is_response_ack(const mcal::peripherals::spi::handle &h_spi)
        {
            h_spi.move_shift_register();
            const auto ack_response{h_spi.read_byte()};
            return static_cast<std::byte>(response::ack) == ack_response;
        }

        bool send_cmd(const mcal::peripherals::spi::handle &h_spi,
                      spi::command cmd)
        {
            h_spi.send(static_cast<std::byte>(cmd));
            h_spi.clear_rx_buffer_not_empty_flag();
            return is_response_ack(h_spi);
        }
    } // namespace

} // namespace hal::arduino
