#ifndef __MECHANISM_H__
#define __MECHANISM_H__

#ifdef __cplusplus
extern "C"
{
#endif

namespace drivers
{
    namespace peripherals
    {
        enum class Mechanism
        {
            polling,
            interrupt
        };

    } // namespace peripherals

} // namespace drivers

#ifdef __cplusplus
}
#endif

#endif // __MECHANISM_H__