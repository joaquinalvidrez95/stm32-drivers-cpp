#include "app/inc/cfg.h"

#if CFG_SAMPLE == CFG_SAMPLE_02_LED_BUTTON

#include "hal/nucleo/f446re/inc/button.h"
#include "hal/nucleo/f446re/inc/led.h"

int main(void)
{
    const hal::nucleo::f446re::led led{};
    const hal::nucleo::f446re::button button{};

    for (;;)
    {
        button.wait_till_pressed();
        led.toggle();
    }
    return 0;
}

#endif
