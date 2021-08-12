/*
 * handle.h
 *
 *  Created on: Aug 11, 2021
 *      Author: joaquin
 */

#ifndef PERIPHERALS_SPI_INC_HANDLE_H_
#define PERIPHERALS_SPI_INC_HANDLE_H_

#include "mcal/peripherals/spi/inc/cfg.h"

namespace mcal
{
    namespace peripherals
    {
        namespace spi
        {
            class Handle
            {
            public:
                Handle(/* args */);
                ~Handle();
                void init(const Cfg *p_cfg);
            private:
                /* data */
            };
           
            
            
        } // namespace spi
        
        
    } // namespace peripherals
    
    
} // namespace mcal




#endif /* PERIPHERALS_SPI_INC_HANDLE_H_ */
