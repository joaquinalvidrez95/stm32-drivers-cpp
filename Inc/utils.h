#ifndef __UTILS_H__
#define __UTILS_H__

#include <stdbool.h>
#include <stdint.h>

namespace utils
{
    void delay();

    /* TODO: Make inline */
    template <typename Integer>
    void set_bits_by_position(volatile Integer &out,
                              Integer position,
                              bool b_set,
                              Integer mask = 1U)
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
    bool is_bit_set(Integer value, Integer bit_position)
    {
        return (value & (1U << bit_position)) != 0U;
    }

} // namespace utils

#endif // __UTILS_H__