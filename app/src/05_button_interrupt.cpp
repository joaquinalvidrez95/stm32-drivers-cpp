#include "hal/nucleo/f446re/inc/button.h"
#include "hal/nucleo/f446re/inc/led.h"
#include "app/inc/cfg.h"
#include "utils/inc/utils.h"

#if CFG_SAMPLE == CFG_SAMPLE_05_BUTTTON_INTERRUPT

namespace
{
    const hal::nucleo::f446re::button g_button{
        mcal::peripherals::mechanism::interrupt};
    const hal::nucleo::f446re::led g_led{};

} // namespace

int main(void)
{
    for (;;)
    {
    }
    return 0;
}

extern "C" void EXTI15_10_IRQHandler()
{
    utils::delay();
    g_button.handle_irq();
    g_led.toggle();
}

#endif
