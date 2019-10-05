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
#include "../source/Pattern/patternGenerator.h"

void runTests(void)
{
	UCUNIT_Init(); /* initialize framework */
	UCUNIT_TestcaseBegin("Pattern Generator Test");
	for(uint8_t i = 0; i < 0xFF; i++)
	{
		UCUNIT_CheckIsEqual(LinearFeedbackShiftRegister(i),LinearFeedbackShiftRegister(i));
	}
	UCUNIT_TestcaseEnd();
	gen_pattern(8, 15);

}
