#include "hal/nucleo/f446re/inc/button.h"
#include "hal/nucleo/f446re/inc/led.h"
#include "cfg.h"
#include "utils.h"

#if CFG_SAMPLE == CFG_SAMPLE_05_BUTTTON_INTERRUPT

static hal::nucleo::f446re::Button g_button{};
static hal::nucleo::f446re::Led g_led{};

int main(void)
{
    g_button.init(mcal::peripherals::Mechanism::interrupt);
    g_led.init();

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
