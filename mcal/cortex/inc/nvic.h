/*
 * stm32f407xx_nvic_driver.h
 *
 *  Created on: Aug 29, 2020
 *      Author: joaquin
 */

#ifndef INC_STM32F446XX_NVIC_DRIVER_H_
#define INC_STM32F446XX_NVIC_DRIVER_H_

#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

	namespace mcal::cortex::nvic
	{
		enum class Irq_num : uint32_t
		{
			exti0 = 6U,
			exti1 = 7U,
			exti2 = 8U,
			exti3 = 9U,
			exti4 = 10U,
			exti9_5 = 23U,
			i2c1_ev = 31U,
			i2c1_er = 32U,
			i2c2_ev = 33U,
			i2c2_er = 34U,
			spi1 = 35U,
			spi2 = 36U,
			usart1 = 37U,
			usart2 = 38U,
			usart3 = 39U,
			exti15_10 = 40U,
			spi3 = 51U,
			uart4 = 52U,
			uart5 = 53U,
			usart6 = 71U,
			i2c3_ev = 72U,
			i2c3_er = 73U,
			spi4 = 84U,
		};

		enum class Irq_prio : uint32_t
		{
			zero,
			one,
			two,
			three,
			four,
			five,
			six,
			seven,
			eight,
			nine,
			ten,
			eleven,
			twelve,
			thirteen,
			fourteen,
			fifteen,
		};

		void set_irq_enabled(Irq_num irq_num, bool b_enabled);
		void set_irq_priority(Irq_num irq_num, Irq_prio prio);
	} // namespace mcal::cortex::nvic

#ifdef __cplusplus
}
#endif

#endif /* INC_STM32F446XX_NVIC_DRIVER_H_ */
