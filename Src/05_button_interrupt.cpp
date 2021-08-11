#include "nucleof446re.h"
#include "cfg.h"
#include "utils.h"

#if CFG_SAMPLE == CFG_SAMPLE_05_BUTTTON_INTERRUPT

static nucleo::F446re gh_nucleo{};

int main(void)
{
    gh_nucleo.init_button(mcal::peripherals::Mechanism::interrupt);
    gh_nucleo.init_led();
    gh_nucleo.set_button_irq_enabled(true);

    for (;;)
    {
    }
    return 0;
}

extern "C" void EXTI15_10_IRQHandler()
{
    utils::delay();
    gh_nucleo.handle_irq_button();
    gh_nucleo.toggle_led();
}

#endif
