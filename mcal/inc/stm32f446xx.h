/*
 * stm32f446xx.h
 *
 *  Created on: May 19, 2020
 *      Author: joaquin
 */

#ifndef INC_STM32F446XX_H_
#define INC_STM32F446XX_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdint.h>

/* ARM Cortex */
#define NVIC_ISER0 (reinterpret_cast<volatile uint32_t *>(0xE000'E100LU))
#define NVIC_ISER1 (reinterpret_cast<volatile uint32_t *>(0xE000'E104LU))
#define NVIC_ISER2 (reinterpret_cast<volatile uint32_t *>(0xE000'E108LU))
#define NVIC_ISER3 (reinterpret_cast<volatile uint32_t *>(0xE000'E10CLU))

#define NVIC_ICER0 (reinterpret_cast<volatile uint32_t *>(0xE000'E180LU))
#define NVIC_ICER1 (reinterpret_cast<volatile uint32_t *>(0xE000'E184LU))
#define NVIC_ICER2 (reinterpret_cast<volatile uint32_t *>(0xE000'E188LU))
#define NVIC_ICER3 (reinterpret_cast<volatile uint32_t *>(0xE000'E18CLU))

#define NVIC_PR_BASE_ADDR (reinterpret_cast<volatile uint32_t *>(0xE000'E400LU))

	namespace mcal::address
	{
		constexpr uint32_t flash{0x0800'0000LU};

		/** 112KB */
		constexpr uint32_t sram1{0x2000'0000LU};

		constexpr uint32_t sram2{0x2000'1C00LU};

		constexpr uint32_t rom_baseaddr{0u};

		constexpr uint32_t sram{sram1};
		constexpr uint32_t peripheral{0x4000'0000LU};

		namespace apb1
		{
			constexpr uint32_t base{peripheral};
			constexpr uint32_t tim2{base};
			constexpr uint32_t tim3{base + 0x0400UL};
			constexpr uint32_t tim4{base + 0x0800UL};
			constexpr uint32_t tim5{base + 0x0C00UL};
			constexpr uint32_t tim6{base + 0x1000UL};
			constexpr uint32_t tim7{base + 0x1400UL};
			constexpr uint32_t tim12{base + 0x1800UL};
			constexpr uint32_t tim13{base + 0x1C00UL};
			constexpr uint32_t tim14{base + 0x2000UL};
			constexpr uint32_t rtc_bkp{base + 0x2800UL};
			constexpr uint32_t wwdg{base + 0x2C00UL};
			constexpr uint32_t iwdg{base + 0x3000UL};
			constexpr uint32_t spi2_i2s2{base + 0x3800LU};
			constexpr uint32_t spi3_i2s3{base + 0x3C00LU};
			constexpr uint32_t spdifrx{base + 0x4000LU};
			constexpr uint32_t usart2{base + 0x4400LU};
			constexpr uint32_t usart3{base + 0x4800LU};
			constexpr uint32_t uart4{base + 0x4c00LU};
			constexpr uint32_t uart5{base + 0x5000LU};
			constexpr uint32_t i2c1{base + 0x5400LU};
			constexpr uint32_t i2c2{base + 0x5800LU};
			constexpr uint32_t i2c3{base + 0x5C00LU};
			constexpr uint32_t fmpi2c1{base + 0x6000LU};
			constexpr uint32_t can1{base + 0x6400LU};
			constexpr uint32_t can2{base + 0x6800LU};
			constexpr uint32_t hdmi_cec{base + 0x6C00LU};
			constexpr uint32_t pwr{base + 0x7000LU};
			constexpr uint32_t dac{base + 0x7400LU};
		} // namespace apb1

		namespace apb2
		{
			constexpr uint32_t base{peripheral + 0x1'0000LU};
			constexpr uint32_t tim1{base};
			constexpr uint32_t tim8{base + 0x0400LU};
			constexpr uint32_t usart1{base + 0x1000LU};
			constexpr uint32_t usart6{base + 0x1400LU};
			constexpr uint32_t adc123{base + 0x2000LU};
			constexpr uint32_t sdio{base + 0x2C00LU};
			constexpr uint32_t spi1{base + 0x3000LU};
			constexpr uint32_t spi4{base + 0x3400LU};
			constexpr uint32_t syscfg{base + 0x3800LU};
			constexpr uint32_t exti{base + 0x3C00LU};
			constexpr uint32_t tim9{base + 0x4000LU};
			constexpr uint32_t tim10{base + 0x4400LU};
			constexpr uint32_t tim11{base + 0x4800LU};
			constexpr uint32_t sai1{base + 0x5800LU};
			constexpr uint32_t sai2{base + 0x5C00LU};
		} // namespace apb2
		namespace ahb1
		{
			constexpr uint32_t base{peripheral + 0x2'0000LU};
			constexpr uint32_t gpioa{base + 0x0000LU};
			constexpr uint32_t gpiob{base + 0x0400LU};
			constexpr uint32_t gpioc{base + 0x0800LU};
			constexpr uint32_t gpiod{base + 0x0c00LU};
			constexpr uint32_t gpioe{base + 0x1000LU};
			constexpr uint32_t gpiof{base + 0x1400LU};
			constexpr uint32_t gpiog{base + 0x1800LU};
			constexpr uint32_t gpioh{base + 0x1c00LU};
			constexpr uint32_t rcc{base + 0x3800LU};
		} // namespace ahb1

		namespace ahb2
		{
			constexpr uint32_t base{0x5000'0000LU};
		} // namespace ahb2
	}	  // namespace mcal
#ifdef __cplusplus
}
#endif

#endif /* INC_STM32F446XX_H_ */
