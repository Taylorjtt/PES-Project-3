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
 * @file MemoryTest.c
 * @brief
 *
 *  @author John Taylor
 * 	@date Oct 8, 2019
 *
 */
#include "MemoryTest.h"

uint32_t * allocate_words(size_t length)
{

	uint32_t * words = (uint32_t*)malloc(length);
	if(words == NULL)
	{
#ifdef FREEDOM
		PRINTF("Warning: Allocation Error\n\r");
#else
		printf("Warning: Allocation Error\n\r");
#endif
	}
	return words;
}
void free_words(uint32_t * src)
{
	if(src == NULL)
	{
#ifdef FREEDOM
		PRINTF("Warning: Source is NULL\n\r");
#else
		printf("Warning: Source is NULL\n\r");
#endif
	}
	free(src);

}
uint8_t * display_memory(uint32_t * loc, size_t length)
{
	uint8_t * mem = (uint8_t*)allocate_words(length);
	memcpy(mem,loc,length);
	return mem;
}
mem_status write_memory(uint32_t * loc, uint8_t value)
{
	uintptr_t pointerAsInt = (uintptr_t)loc;
	if(loc == NULL)
	{
		return FAILED;
	}
	else
	{
		if(pointerAsInt % 4 == 0)
		{

			*loc &= 0xFFFFFF00;
			*loc = *loc | value << 0;
			return SUCCESS;
		}
		else if(pointerAsInt % 4 == 1)
		{
			loc = get_address(loc, -1);
			*loc &= 0xFFFF00FF;
			*loc = *loc | value << 8;

			return SUCCESS;
		}
		else if((pointerAsInt % 4) == 2)
		{
			loc = get_address(loc, -2);
			*loc &= 0xFF00FFFF;
			*loc = *loc | value << 16;
			return SUCCESS;
		}
		else if(pointerAsInt % 4 == 3)
		{
			loc = get_address(loc, -3);
			*loc &= 0x00FFFFFF;
			*loc = *loc | value << 24;
			return SUCCESS;
		}
		else
		{
			return FAILED;
		}

	}
}
mem_status invert_block(uint32_t * loc, size_t length)
{
	if(loc == NULL)
	{
		return FAILED;
	}
	uint8_t* vals = display_memory(loc, length);
	for(int i = 0; i < length; i++)
	{
		if(write_memory(get_address(loc, i), vals[i] ^ 0xFFFF) == FAILED)
		{
			return FAILED;
		}
	}
	return SUCCESS;
}
mem_status write_pattern(uint32_t * loc, size_t length, int8_t seed)
{
	if(loc == NULL)
	{
		return FAILED;
	}
	gen_pattern((uint8_t*)(loc), length, seed);
	return SUCCESS;
}
uint32_t * verify_pattern(uint32_t * loc, size_t length, int8_t seed)
{
	uint32_t* pattern = allocate_words(length);
	gen_pattern((uint8_t*)pattern, length, seed);
	uint32_t * errors = allocate_words(length*sizeof(uint32_t));
	for(uint8_t i = 0; i < length; i++)
	{
		uint8_t valueOne = *((uint8_t *)loc + i);
		uint8_t valueTwo = *((uint8_t *)pattern + i);
		if(valueOne != valueTwo)
		{
			#ifdef FREEDOM
			PRINTF("Pattern Verification Error\n\r");
			#else
			printf("Pattern Verification Error\n\r");
			#endif
			errors[i] = (uintptr_t)loc;
		}
		else
		{
			errors[i] = (uint32_t)0;
		}
	}
	free_words(pattern);
	return errors;

}
uint32_t * get_address(uint32_t * loc, int8_t offset)
{
	uint32_t* tmp = loc;
	uint8_t* ptr = (uint8_t *)loc;
	ptr+=offset;
	tmp = (uint32_t*)ptr;
	return  tmp;
}

