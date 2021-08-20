/**
 * @file 07_spi_tx_only_arduino.cpp
 * @author Joaquin Alan Alvidrez Soto
 * @brief 
 * @date 2021-08-19
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <array>
#include <cstddef>

#include "mcal/peripherals/spi/inc/handle.h"
#include "mcal/peripherals/spi/inc/cfg.h"
#include "hal/nucleo/f446re/inc/spi.h"
#include "app/inc/cfg.h"
#include "utils/inc/utils.h"

#if CFG_SAMPLE == CFG_SAMPLE_07_SPI_TX_ONLY_ARDUINO

int main(void)
{
    for (;;)
    {
    }
    return 0;
}

#endif
