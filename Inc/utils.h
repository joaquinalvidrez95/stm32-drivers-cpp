#ifndef __UTILS_H__
#define __UTILS_H__

#include <stdbool.h>
#include <stdint.h>
class Utils
{

public:
    static void delay();

    /* TODO: Make inline */
    template <typename Integer>
    static void set_bits_by_position(volatile Integer &out, Integer position, bool b_set, Integer mask = 1u)
    {
        if (b_set)
        {
            out |= mask << position;
        }
        else
        {
            out &= ~(mask << position);
        }
    }

    template <typename Integer>
    static bool is_bit_set(Integer value, Integer bit_position)
    {
        return (value & (1u << bit_position)) != 0u;
    }
};

#endif // __UTILS_H__