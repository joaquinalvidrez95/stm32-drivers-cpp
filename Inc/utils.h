#ifndef __UTILS_H__
#define __UTILS_H__

#include <stdbool.h>
#include <stdint.h>
class Utils
{

public:
    static void delay();

    template <typename T>
    static void set_bit_by_position(volatile T &p_reg, uint8_t position, bool b_set)
    {
        if (b_set)
        {
            p_reg |= static_cast<T>(1u << position);
        }
        else
        {
            p_reg &= static_cast<T>(~(1u << position));
        }
    }
};

#endif // __UTILS_H__