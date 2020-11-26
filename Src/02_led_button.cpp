#include "drivers/peripherals/gpio/inc/gpio.h"
#include "utils.h"
#include "nucleof446re.h"
#include "cfg.h"

#if CFG_SAMPLE == CFG_SAMPLE_02_LED_BUTTON

int main(void)
{
    nucleo::F446re h_nucleo{};
    h_nucleo.init_button();
    h_nucleo.init_led();

    for (;;)
    {
        h_nucleo.wait_till_button_pressed();
        h_nucleo.toggle_led();
    }
    return 0;
}

#endif