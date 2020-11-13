/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#include "drivers/peripherals/inc/gpio.h"
#include "utils.h"

int main(void)
{
#if 1
  const drivers::peripherals::gpio::Configuration cfg{
      .number = drivers::peripherals::gpio::GPIO_PIN_5,
      .mode = drivers::peripherals::gpio::Mode::out,
      .speed = drivers::peripherals::gpio::GPIO_SPEED_FAST,
      .pull_mode = drivers::peripherals::gpio::GPIO_PULL_MODE_NONE,
      .out_type = drivers::peripherals::gpio::GPIO_OUT_TYPE_PUSH_PULL,
      .alt_fun_mode = drivers::peripherals::gpio::GPIO_ALTERNATE_FUNCTION_0,
      .channel = drivers::peripherals::gpio::Channel::a,
  };
  drivers::peripherals::gpio::Gpio_handle h{cfg};
  h.init();
  while (1)
  {
    h.toggle_pin();
    Utils::delay();
  }
#endif
  return 0;
}