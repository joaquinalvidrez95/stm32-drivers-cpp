/*
 * exti.h
 *
 *  Created on: Aug 13, 2021
 *      Author: joaquin
 */

#ifndef INC_EXTI_H_
#define INC_EXTI_H_

#include <cstdint>

namespace mcal
{
    struct Exti_reg
    {
        volatile uint32_t imr;
        volatile uint32_t emr;
        volatile uint32_t rtsr;
        volatile uint32_t ftsr;
        volatile uint32_t swier;
        volatile uint32_t pr;
    };
} // namespace mcal

#define EXTI (reinterpret_cast<mcal::Exti_reg *>(mcal::address::apb2::exti))

#endif /* INC_EXTI_H_ */
