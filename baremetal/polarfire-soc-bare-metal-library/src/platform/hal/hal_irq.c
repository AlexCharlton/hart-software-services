/*******************************************************************************
 * Copyright 2019-2025 Microchip FPGA Embedded Systems Solutions.
 *
 * SPDX-License-Identifier: MIT
 *
 * MPFS HAL Embedded Software
 *
 */
/***************************************************************************//**
 *
 * Legacy interrupt control functions for the Microchip driver library hardware
 * abstraction layer.
 *
 */
#include <stdio.h>
#include "hal/hal.h"
#include "atomic.h"
#include "encoding.h"
//#include "mpfs_hal/mcall.h"
#include "mss_util.h"
#include "mss_mtrap.h"

#ifdef __cplusplus
extern "C" {
#endif

/*------------------------------------------------------------------------------
 *
 */
void HAL_enable_interrupts(void) {
    __enable_irq();
}

/*------------------------------------------------------------------------------
 *
 */
psr_t HAL_disable_interrupts(void) {
    psr_t psr;
    psr = read_csr(mstatus);
    __disable_irq();
    return(psr);
}

/*------------------------------------------------------------------------------
 *
 */
void HAL_restore_interrupts(psr_t saved_psr) {
    write_csr(mstatus, saved_psr);
}

#ifdef __cplusplus
}
#endif

