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
 * @file tests.c
 * @brief
 *
 *  @author John Taylor
 * 	@date Oct 5, 2019
 *
 */
#include "tests.h"
#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MKL25Z4.h"
#include "fsl_debug_console.h"
#include "../source/Pattern/patternGenerator.h"

void runTests(void)
{
  	/* Init board hardware. */
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();
  	/* Init FSL debug console. */
    BOARD_InitDebugConsole();
	UCUNIT_Init(); /* initialize framework */
	UCUNIT_TestcaseBegin("Pattern Generator Test");
	for(uint8_t i = 0; i < 0xFF; i++)
	{
		//test that LFSR values are the same for a same seed
		UCUNIT_CheckIsEqual(LinearFeedbackShiftRegister(i),LinearFeedbackShiftRegister(i));
	}
	UCUNIT_TestcaseEnd();
}

int main()
{
	runTests();
}
