#ifndef __UTILS_H__
#define __UTILS_H__

#include <stdbool.h>
#include <stdint.h>

namespace utils
{
    void delay();

    /* TODO: Make inline */
    template <typename Integer>
    Integer set_bits_by_position(Integer in,
                                  Integer position,
                                  bool b_set = true,
                                  Integer mask = 1U)
    {
        return b_set ? (in | (mask << position)) : (in & ~(mask << position));
    }

    template <typename Integer>
    bool is_bit_set(Integer value, Integer bit_position)
    {
        return (value & (1U << bit_position)) != 0U;
    }

} // namespace utils

#endif // __UTILS_H__