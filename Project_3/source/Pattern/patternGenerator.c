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
 * @file patternGenerator.c
 * @brief
 *
 *  @author John Taylor
 * 	@date Oct 5, 2019
 *
 */
#include "patternGenerator.h"

uint8_t* gen_pattern(uint8_t* buffer,size_t length, uint8_t seed)
{

	for(int i = 0; i < length; i++)
	{
		pattern[i] = LinearFeedbackShiftRegister(seed + i);
	}

	PRINTF("0x");
	for(int i = 0; i < length; i++)
	{
		PRINTF("%X",pattern[i]);
	}
	PRINTF("\n\r");

	return pattern;
}

uint8_t LinearFeedbackShiftRegister(uint8_t seed)
{
	//https://en.wikipedia.org/wiki/Linear-feedback_shift_register
	uint8_t start_state = seed;  /* Any nonzero start state will work. */
	uint8_t lfsr = start_state;

	for(int i = 0; i < 8; i++)
	{
		uint8_t lsb = lfsr  & 1; //get the least significant bit
		lfsr >>= 1; // shift
		if(lsb)
		{
			lfsr ^= 0xB4;
		}
	}

	//PRINTF("0x%X\n\r",lfsr);
	return lfsr;


}
