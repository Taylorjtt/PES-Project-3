/*****************************************************************************
* Copyright (C) 2019 by John Taylor
*
* Redistribution, modification or use of this software in source or binary
* forms is permitted as long as the files maintain this copyright. Users are
* permitted to modify this and use it to learn about the field of embedded
* software. John Taylor and the University of Colorado are not liable for
* any misuse of this material.
*
*****************************************************************************/
/*
 * @file Project_3.h
 * @brief
 *
 *  @author John Taylor
 * 	@date Oct 14, 2019
 *
 */
#ifndef PROJECT_3_H_
#define PROJECT_3_H_
#include <stdio.h>
#include <stdlib.h>
#ifdef FREEDOM
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MKL25Z4.h"
#include "fsl_debug_console.h"
#endif
#define SEED 0xA
#define LENGTH 16
#include "Pattern/patternGenerator.h"
#include "MemoryTest/MemoryTest.h"
#include "Logger/logger.h"
extern LoggerHandle logger;

#endif /* PROJECT_3_H_ */
