#ifndef __MECHANISM_H__
#define __MECHANISM_H__

#ifdef __cplusplus
extern "C"
{
#endif

namespace mcal
{
    namespace peripherals
    {
        enum class Mechanism
        {
            polling,
            interrupt
        };

    } // namespace peripherals

} // namespace mcal

#ifdef __cplusplus
}
#endif

#endif // __MECHANISM_H__