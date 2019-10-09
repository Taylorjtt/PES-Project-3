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
 * @file patternGenerator.h
 * @brief
 *
 *  @author John Taylor
 * 	@date Oct 5, 2019
 *
 */
#include <stdint.h>
#include <stdlib.h>
#ifdef FREEDOM
#include "fsl_debug_console.h"
#endif

/**
* @brief Function to generate arbitrary length pseudo random
* byte pattern
*
*
* @param pattern	byte pattern buffer
* @param length 	length of the pattern
* @param seed		16 bit seed value
* @return void
*/
void gen_pattern(uint8_t* pattern,size_t length, uint8_t seed);


/**
* @brief Implementation of a Linear Feedback Shift Register
*
*
* @param seed		16 bit seed value
* @return void
*/
uint8_t LinearFeedbackShiftRegister(uint16_t seed);
