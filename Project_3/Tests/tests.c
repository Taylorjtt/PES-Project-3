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
	UCUNIT_TestcaseEnd();

	UCUNIT_TestcaseBegin("Write Memory Test");
	chonk = allocate_words(16);
	for(uint8_t i = 0; i < 16; i++)
	{
		write_memory(get_address(chonk, i), i);
	}
	for(uint8_t i = 0; i < 16; i++)
	{
		uint8_t val = *((uint8_t *)chonk + i);
		PRINTF("Index: %X  inArray: %X\n\r",i,val);
		UCUNIT_CheckIsEqual(i,val);
	}
	UCUNIT_TestcaseEnd();

	UCUNIT_TestcaseBegin("Display Memory Test");
	uint8_t* chonkCopy = display_memory(chonk, 16);

	for(uint8_t i = 0; i < 16; i++)
	{
		uint8_t val = *(chonkCopy + i);
		PRINTF("Index: %X  inArray: %X\n\r",i,val);
		UCUNIT_CheckIsEqual(i,val);
	}
	UCUNIT_TestcaseEnd();

	UCUNIT_TestcaseBegin("Invert Block Test");
	invert_block(chonk, 16);
	for(uint8_t i = 0; i < 16; i++)
	{
		uint8_t val = *((uint8_t *)chonk + i);
		PRINTF("Index: %X  inArray: %X\n\r",i ^ 0xFF,val);
		UCUNIT_CheckIsEqual(i ^ 0xFF,val);
	}
	UCUNIT_TestcaseEnd();

	UCUNIT_TestcaseBegin("Write Pattern Test");
	write_pattern(chonk, 16, 0xA);
	gen_pattern(chonkCopy, 16, 0xA);
	for(uint8_t i = 0; i < 16; i++)
	{
		uint8_t valueOne = *((uint8_t *)chonk + i);
		uint8_t valueTwo = *(chonkCopy + i);
		PRINTF("Index: %X  inArray: %X\n\r",valueOne,valueTwo);
		UCUNIT_CheckIsEqual(valueTwo,valueOne);
	}
	UCUNIT_TestcaseEnd();
	UCUNIT_TestcaseBegin("Verify Pattern Test");
	uint32_t* errors = verify_pattern(chonk, 16, 0xA);
	for(int i = 0; i < 16; i++)
	{

		UCUNIT_CheckIsEqual(0,errors[i]);
	}

	//specifically change all of the values in the chonk array and make sure that
	//the returned array is an array of all of the addresses represented by chonk

	invert_block(chonk, 16);
	errors = verify_pattern(chonk, 16, 0xA);
	for(int i = 0; i < 16; i++)
	{
		UCUNIT_CheckIsEqual((uint32_t)chonk,errors[i]);
	}
	UCUNIT_TestcaseEnd();

	free_words(chonk);
	free_words((uint32_t*)chonkCopy);

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
