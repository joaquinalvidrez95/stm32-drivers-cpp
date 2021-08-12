/*
 * reg.h
 *
 *  Created on: Aug 11, 2021
 *      Author: joaquin
 */

#ifndef PERIPHERALS_RCC_INC_REG_H_
#define PERIPHERALS_RCC_INC_REG_H_

#include <cstdint>
#include <cstddef>

#include "mcal/peripherals/rcc/inc/ahb.h"
#include "mcal/peripherals/rcc/inc/aph.h"

namespace mcal
{
    namespace peripherals
    {
        namespace rcc
        {
            struct Reg
            {
                volatile uint32_t cr;
                volatile uint32_t pll_cfgr;
                volatile uint32_t cfgr;
                volatile uint32_t cir;
                volatile uint32_t ahbrstr[static_cast<size_t>(ahb::Bus::total)];
                uint32_t _reserved_1;
                volatile uint32_t apbrstr[static_cast<size_t>(apb::Bus::total)];
                uint32_t _reserved_2[2];
                volatile uint32_t ahbenr[static_cast<size_t>(ahb::Bus::total)];
                uint32_t _reserved_3;
                volatile uint32_t apbenr[static_cast<size_t>(apb::Bus::total)];
                uint32_t _reserved_4[2];
                volatile uint32_t ahblpenr[static_cast<size_t>(ahb::Bus::total)];
                uint32_t _reserved_5;
                volatile uint32_t apblpenr[static_cast<size_t>(apb::Bus::total)];
                uint32_t _reserved_6[2];
                volatile uint32_t bdcr;
                volatile uint32_t csr;
                uint32_t _reserved_7[2];
                volatile uint32_t sscgr;
                volatile uint32_t plli2scfgr;
                volatile uint32_t pllsaicfgr;
                volatile uint32_t dckcfgr;
                volatile uint32_t ckgatenr;
                volatile uint32_t dckcfgr2;
            };

#define RCC (reinterpret_cast<Reg *>(RCC_BASEADDR))

        } // namespace rcc

    } // namespace peripherals

} // namespace mcal

#endif /* PERIPHERALS_RCC_INC_REG_H_ */
