#include "hal/nucleo/f446re/inc/button.h"
#include "hal/nucleo/f446re/inc/led.h"
#include "app/inc/cfg.h"
#include "utils/inc/utils.h"

#if CFG_SAMPLE == CFG_SAMPLE_05_BUTTTON_INTERRUPT

namespace
{
    const hal::nucleo::f446re::Button g_button{
        mcal::peripherals::Mechanism::interrupt};
    const hal::nucleo::f446re::Led g_led{};

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
