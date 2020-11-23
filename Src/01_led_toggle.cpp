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

#include "drivers/peripherals/gpio/inc/gpio.h"
#include "utils.h"

int main(void)
{
  const drivers::peripherals::gpio::Configuration cfg{
      drivers::peripherals::gpio::Configuration::Channel::a,
      drivers::peripherals::gpio::Configuration::Pin_num::five,
      drivers::peripherals::gpio::Configuration::Mode::out,
      drivers::peripherals::gpio::Configuration::Out_type::push_pull,
      drivers::peripherals::gpio::Configuration::Pull_mode::none,
      drivers::peripherals::gpio::Configuration::Speed::fast,
      drivers::peripherals::gpio::Configuration::Alternate_function::zero,
  };
  drivers::peripherals::gpio::Handle h{cfg};
  h.init();
  while (1)
  {
    h.toggle_pin();
    Utils::delay();
  }
  return 0;
}
