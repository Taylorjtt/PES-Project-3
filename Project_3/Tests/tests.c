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
#include "../source/MemoryTest/MemoryTest.h"
void testPatternGenerator()
{
	UCUNIT_TestcaseBegin("Pattern Generator Test");
	for(uint8_t i = 0; i < 0xFF; i++)
	{
		//test that LFSR values are the same for a same seed
		UCUNIT_CheckIsEqual(LinearFeedbackShiftRegister(i),LinearFeedbackShiftRegister(i));
	}
	UCUNIT_TestcaseEnd();
}
void testMemoryFunctions()
{
	UCUNIT_TestcaseBegin("Memory Allocation Test");
	uint32_t * chonk = allocate_words(5);
	UCUNIT_CheckIsNotNull(chonk);
	UCUNIT_CheckIs32Bit(*chonk);
	free_words(chonk);
	chonk = allocate_words(200000);
	UCUNIT_CheckIsNull(chonk);
	free_words(chonk);

	chonk = allocate_words(16);

	for(int i = 0; i < 16; i++)
	{
		write_memory(chonk, i);
	}

	uint8_t* chonkCopy = display_memory(chonk, 16);

	for(int i = 0; i < 16; i++)
	{
		PRINTF("Index: %X  inArray: %\n\r",i,chonkCopy[i]);
		UCUNIT_CheckIsEqual(i,chonkCopy[i]);
	}

	UCUNIT_TestcaseEnd();
}
void runTests(void)
{


	testPatternGenerator();
	testMemoryFunctions();
}
void init()
{
  	/* Init board hardware. */
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();
  	/* Init FSL debug console. */
    BOARD_InitDebugConsole();
	UCUNIT_Init(); /* initialize framework */
}

int main()
{
	init();
	runTests();
	return 0;
}
