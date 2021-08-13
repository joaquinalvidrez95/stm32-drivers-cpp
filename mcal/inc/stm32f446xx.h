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
#define NVIC_ISER0 (reinterpret_cast<volatile uint32_t *>(0xE000E100U))
#define NVIC_ISER1 (reinterpret_cast<volatile uint32_t *>(0xE000E104U))
#define NVIC_ISER2 (reinterpret_cast<volatile uint32_t *>(0xE000E108U))
#define NVIC_ISER3 (reinterpret_cast<volatile uint32_t *>(0xE000E10CU))

#define NVIC_ICER0 (reinterpret_cast<volatile uint32_t *>(0xE000E180U))
#define NVIC_ICER1 (reinterpret_cast<volatile uint32_t *>(0xE000E184U))
#define NVIC_ICER2 (reinterpret_cast<volatile uint32_t *>(0xE000E188U))
#define NVIC_ICER3 (reinterpret_cast<volatile uint32_t *>(0xE000E18CU))

#define NVIC_PR_BASE_ADDR (reinterpret_cast<volatile uint32_t *>(0xE000E400U))

#define FLASH_BASEADDR (0x08000000LU)

/** 112KB */
#define SRAM1_BASEADDR (0x20000000LU)

#define SRAM2_BASEADDR (0x20001C00LU)

/** */
#define ROM_BASEADDR

#define SRAM (SRAM1_BASEADDR)

#define PERIPH_BASE (0x40000000LU)
#define APB1PERIPH_BASE (PERIPH_BASE)
#define APB2PERIPH_BASE (0x40010000LU)
#define AHB1PERIPH_BASE (0x40020000LU)
#define AHB2PERIPH_BASE (0x50000000LU)

// TODO: Check if constexpr can be used
/** AHB1 */
#define GPIOA_BASEADDR (AHB1PERIPH_BASE + 0x0000U)
#define GPIOB_BASEADDR (AHB1PERIPH_BASE + 0x0400U)
#define GPIOC_BASEADDR (AHB1PERIPH_BASE + 0x0800U)
#define GPIOD_BASEADDR (AHB1PERIPH_BASE + 0x0C00U)
#define GPIOE_BASEADDR (AHB1PERIPH_BASE + 0x1000U)
#define GPIOF_BASEADDR (AHB1PERIPH_BASE + 0x1400U)
#define GPIOG_BASEADDR (AHB1PERIPH_BASE + 0x1800U)
#define GPIOH_BASEADDR (AHB1PERIPH_BASE + 0x1C00U)

#define RCC_BASEADDR (AHB1PERIPH_BASE + 0x3800U)

/** APB1 */
#define I2C1_BASEADDR (APB1PERIPH_BASE + 0x5400U)
#define I2C2_BASEADDR (APB1PERIPH_BASE + 0x5800U)
#define I2C3_BASEADDR (APB1PERIPH_BASE + 0x5C00U)

#define SPI2_BASEADDR (APB1PERIPH_BASE + 0x3800U)
#define SPI3_BASEADDR (APB1PERIPH_BASE + 0x3C00U)

#define USART2_BASEADDR (APB1PERIPH_BASE + 0x4400U)
#define USART3_BASEADDR (APB1PERIPH_BASE + 0x4800U)

#define UART4_BASEADDR (APB1PERIPH_BASE + 0x4C00U)
#define UART5_BASEADDR (APB1PERIPH_BASE + 0x5000U)

/** APB2 */
#define SPI1_BASEADDR (APB2PERIPH_BASE + 0x3000U)
#define SPI4_BASEADDR (APB2PERIPH_BASE + 0x3400U)

#define EXTI_BASEADDR (APB2PERIPH_BASE + 0x3C00U)

#define USART1_BASEADDR (APB2PERIPH_BASE + 0x1000U)
#define USART6_BASEADDR (APB2PERIPH_BASE + 0x1400U)

#define SYSCFG_BASEADDR (APB2PERIPH_BASE + 0x3800U)

	/** Registers */
	struct Exti_reg
	{
		volatile uint32_t imr;
		volatile uint32_t emr;
		volatile uint32_t rtsr;
		volatile uint32_t ftsr;
		volatile uint32_t swier;
		volatile uint32_t pr;
	};

	struct Syscfg_reg
	{
		volatile uint32_t memrmp;
		volatile uint32_t pmc;
		/* TODO: Remove magic number */
		volatile uint32_t exticr[4];
		uint32_t reserved1[2];
		volatile uint32_t cmpcr;
		uint32_t reserved2[2];
		volatile uint32_t cfgr;
	};

#define EXTI (reinterpret_cast<Exti_reg *>(EXTI_BASEADDR))
#define SYSCFG (reinterpret_cast<Syscfg_reg *>(SYSCFG_BASEADDR))

#ifdef __cplusplus
}
#endif

#endif /* INC_STM32F446XX_H_ */
