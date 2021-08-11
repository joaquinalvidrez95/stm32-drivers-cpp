#include "hal/nucleo/f446re/inc/button.h"
#include "hal/nucleo/f446re/inc/led.h"
#include "cfg.h"

#if CFG_SAMPLE == CFG_SAMPLE_02_LED_BUTTON

int main(void)
{
    hal::nucleo::f446re::Led led{};
    hal::nucleo::f446re::Button button{};
    led.init();
    button.init();

    for (;;)
    {
        button.wait_till_pressed();
        led.toggle();
    }
    return 0;
}

#endif