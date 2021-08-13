/*
 * syscfg.h
 *
 *  Created on: Aug 13, 2021
 *      Author: joaquin
 */

#ifndef INC_SYSCFG_H_
#define INC_SYSCFG_H_

#include <cstdint>

namespace mcal
{
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
} // namespace mcal

#define SYSCFG (reinterpret_cast<mcal::Syscfg_reg *>(mcal::address::apb2::syscfg))

#endif /* INC_SYSCFG_H_ */
