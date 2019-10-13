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
 * @file MemoryTest.h
 * @brief
 *
 *  @author John Taylor
 * 	@date Oct 8, 2019
 *
 */
#ifndef MEMORYTEST_MEMORYTEST_H_
#define MEMORYTEST_MEMORYTEST_H_
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Pattern/patternGenerator.h"

typedef enum mem_status
{
	SUCCESS = 0, // no error
	FAILED // failure case
} mem_status;

uint32_t * allocate_words(size_t length);
void free_words(uint32_t * src);
uint8_t * display_memory(uint32_t * loc, size_t length);
mem_status write_memory(uint32_t * loc, uint8_t value);
mem_status invert_block(uint32_t * loc, size_t length);
mem_status write_pattern(uint32_t * loc, size_t length, int8_t seed);
uint32_t * verify_pattern(uint32_t * loc, size_t length, int8_t seed);
uint32_t * get_address(uint32_t * loc, int8_t offset);


#endif /* MEMORYTEST_MEMORYTEST_H_ */
