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
#define NVIC_ISER0 ((volatile uint32_t *)0xE000E100u)
#define NVIC_ISER1 ((volatile uint32_t *)0xE000E104u)
#define NVIC_ISER2 ((volatile uint32_t *)0xE000E108u)
#define NVIC_ISER3 ((volatile uint32_t *)0xE000E10Cu)

#define NVIC_ICER0 ((volatile uint32_t *)0xE000E180u)
#define NVIC_ICER1 ((volatile uint32_t *)0xE000E184u)
#define NVIC_ICER2 ((volatile uint32_t *)0xE000E188u)
#define NVIC_ICER3 ((volatile uint32_t *)0xE000E18Cu)

#define NVIC_PR_BASE_ADDR ((volatile uint32_t *)0xE000E400U)

#define FLASH_BASEADDR 0x08000000LU

/** 112KB */
#define SRAM1_BASEADDR 0x20000000LU

#define SRAM2_BASEADDR 0x20001C00LU

/** */
#define ROM_BASEADDR

#define SRAM SRAM1_BASEADDR

#define PERIPH_BASE (0x40000000LU)
#define APB1PERIPH_BASE PERIPH_BASE
#define APB2PERIPH_BASE (0x40010000LU)
#define AHB1PERIPH_BASE (0x40020000LU)
#define AHB2PERIPH_BASE (0x50000000LU)

/** AHB1 */
#define GPIOA_BASEADDR (AHB1PERIPH_BASE + 0x0000u)
#define GPIOB_BASEADDR (AHB1PERIPH_BASE + 0x0400u)
#define GPIOC_BASEADDR (AHB1PERIPH_BASE + 0x0800u)
#define GPIOD_BASEADDR (AHB1PERIPH_BASE + 0x0C00u)
#define GPIOE_BASEADDR (AHB1PERIPH_BASE + 0x1000u)
#define GPIOF_BASEADDR (AHB1PERIPH_BASE + 0x1400u)
#define GPIOG_BASEADDR (AHB1PERIPH_BASE + 0x1800u)
#define GPIOH_BASEADDR (AHB1PERIPH_BASE + 0x1C00u)

#define RCC_BASEADDR (AHB1PERIPH_BASE + 0x3800u)

/** APB1 */
#define I2C1_BASEADDR (APB1PERIPH_BASE + 0x5400u)
#define I2C2_BASEADDR (APB1PERIPH_BASE + 0x5800u)
#define I2C3_BASEADDR (APB1PERIPH_BASE + 0x5C00u)

#define SPI2_BASEADDR (APB1PERIPH_BASE + 0x3800u)
#define SPI3_BASEADDR (APB1PERIPH_BASE + 0x3C00u)

#define USART2_BASEADDR (APB1PERIPH_BASE + 0x4400u)
#define USART3_BASEADDR (APB1PERIPH_BASE + 0x4800u)

#define UART4_BASEADDR (APB1PERIPH_BASE + 0x4C00u)
#define UART5_BASEADDR (APB1PERIPH_BASE + 0x5000u)

/** APB2 */
#define SPI1_BASEADDR (APB2PERIPH_BASE + 0x3000u)
#define SPI4_BASEADDR (APB2PERIPH_BASE + 0x3400u)

#define EXTI_BASEADDR (APB2PERIPH_BASE + 0x3C00u)

#define USART1_BASEADDR (APB2PERIPH_BASE + 0x1000u)
#define USART6_BASEADDR (APB2PERIPH_BASE + 0x1400u)

#define SYSCFG_BASEADDR (APB2PERIPH_BASE + 0x3800u)

	/** Registers */

	typedef struct
	{
		uint16_t CR1;
		const uint16_t _unused_0;
		uint16_t CR2;
		const uint16_t _unused_1;
		uint16_t OAR1;
		const uint16_t _unused_2;
		uint16_t OAR2;
		const uint16_t _unused_3;
		uint8_t DR;
		const uint8_t _unused_4;
		const uint16_t _unused_5;
		uint16_t SR1;
		const uint16_t _unused_6;
		uint16_t SR2;
		const uint16_t _unused_7;
		uint16_t CCR;
		const uint16_t _unused_8;
		uint16_t TRISE;
		const uint16_t _unused_9;
		uint16_t FLTR;
		const uint16_t _unused_10;
	} i2c_reg_t;

	
	typedef struct
	{
		volatile uint32_t imr;
		volatile uint32_t emr;
		volatile uint32_t rtsr;
		volatile uint32_t ftsr;
		volatile uint32_t swier;
		volatile uint32_t pr;
	} exti_reg_t;

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

#define EXTI ((exti_reg_t *)EXTI_BASEADDR)
#define SYSCFG ((Syscfg_reg *)SYSCFG_BASEADDR)

#define I2C1 ((volatile i2c_reg_t *)I2C1_BASEADDR)
#define I2C2 ((volatile i2c_reg_t *)I2C2_BASEADDR)
#define I2C3 ((volatile i2c_reg_t *)I2C3_BASEADDR)

/* TODO: Remove. This is not necessary */
/** Enables USARTx */
#define USART1_PCLK_EN() (RCC->APBENR[1] |= (1u << 4u))
#define USART2_PCLK_EN() (RCC->APBENR[0] |= (1u << 17u))
#define USART3_PCLK_EN() (RCC->APBENR[0] |= (1u << 18u))
#define USART6_PCLK_EN() (RCC->APBENR[1] |= (1u << 5u))

#ifdef __cplusplus
}
#endif

#endif /* INC_STM32F446XX_H_ */
