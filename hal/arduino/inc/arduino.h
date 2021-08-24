/**
 * @file arduino.h
 * @author Joaquin Alan Alvidrez Soto
 * @brief 
 * @date 2021-08-23
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef HAL_ARDUINO_INC_ARDUINO_H
#define HAL_ARDUINO_INC_ARDUINO_H

namespace hal::arduino
{
    enum class digital_pin
    {
        p0,
        p1,
        p2,
        p3,
        p4,
        p5,
        p6,
        p7,
        p8,
        p9,
        p10,
        p11,
        p12,
        p13,
    };

    enum class analog_pin
    {
        p0,
        p1,
        p2,
        p3,
        p4,
    };

} // namespace hal::arduino

#endif // HAL_ARDUINO_INC_ARDUINO_H