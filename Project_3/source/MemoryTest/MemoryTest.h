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
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Pattern/patternGenerator.h"
#include "../Logger/logger.h"
#include "../Project_3.h"

typedef enum mem_status
{
	SUCCESS = 0, // no error
	FAILED // failure case
} mem_status;

/**
* @brief allocate length bytes of memory
*
*
* @param length		amount of bytes to allocate
* @return pointer to the beginning of the allocated bytes
*/
uint32_t * allocate_words(size_t length);
/**
* @brief free memory
*
*
* @param src		beginning of the memory to free
* @return void
*/
void free_words(uint32_t * src);
/**
* @brief make a copy of the memory starting at loc and ending at loc + length and
* store it in the return value
*
* @param loc		where to start copying
* @param length		how much to copy
* @return pointer to the beginning of the array copy
*/
uint8_t * display_memory(uint32_t * loc, size_t length);
/**
* @brief write an 8-bit value to the address loc
*
* @param loc			address to write to
* @param value			what to write
* @return mem_status	success or failure
*/
mem_status write_memory(uint32_t * loc, uint8_t value);
/**
* @brief invert a block of memory starting at loc and ending
* at loc + length
*
* @param loc			address to start at
* @param length			how much to invert
* @return mem_status	success or failure
*/
mem_status invert_block(uint32_t * loc, size_t length);
/**
* @brief write a psuedo random pattern to memory starting at loc and ending
* at loc + length
*
* @param loc			address to start at
* @param length			pattern length
* @return mem_status	success or failure
*/
mem_status write_pattern(uint32_t * loc, size_t length, int8_t seed);
/**
* @brief The user specifies an address, a number of bytes, and a seed value. Using
* the seed value and the pattern generator utility, this function generate a byte array with random values
* based on the seed. The function checks whether the newly generated pattern in the byte array returned
* matches the existing byte pattern in memory at the specified address. The function
* returns a list of any memory location addresses (compare bytes) where memory did not
* match the pattern.
*
* @param loc			address to start at
* @param length			pattern length
* @param seed			RNG seed
* @return				array of failed addresses
*/
uint32_t * verify_pattern(uint32_t * loc, size_t length, int8_t seed);
/**
* this function will take an offset from a specified location and calculate a fully
* addressed memory location for use in the functions above. In this way, memory can be
* more easily addressed by an offset in the region intended for use.
*
* @param loc			address to start at
* @param offset			offset from base address
* @return				loc+offset
*/
uint32_t * get_address(uint32_t * loc, int8_t offset);


#endif /* MEMORYTEST_MEMORYTEST_H_ */
