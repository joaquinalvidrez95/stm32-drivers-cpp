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

	namespace drivers
	{
		namespace cortex
		{
			namespace nvic
			{
				enum class Irq_num : uint32_t
				{
					exti0 = 6u,
					exti1 = 7u,
					exti2 = 8u,
					exti3 = 9u,
					exti4 = 10u,
					exti9_5 = 23u,
					i2c1_ev = 31u,
					i2c1_er = 32u,
					i2c2_ev = 33u,
					i2c2_er = 34u,
					spi1 = 35u,
					spi2 = 36u,
					usart1 = 37u,
					usart2 = 38u,
					usart3 = 39u,
					exti15_10 = 40u,
					spi3 = 51u,
					uart4 = 52u,
					uart5 = 53u,
					usart6 = 71u,
					i2c3_ev = 72u,
					i2c3_er = 73u,
					spi4 = 84u,
				};

				enum class Irq_prio : uint32_t
				{
					zero = 0u,
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
			} // namespace nvic

		} // namespace cortex

	} // namespace drivers

#ifdef __cplusplus
}
#endif

#endif /* INC_STM32F446XX_NVIC_DRIVER_H_ */
