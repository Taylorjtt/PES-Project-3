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
	uint32_t * words = (uint32_t *)malloc(length);
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
	if(loc == NULL)
	{
		return FAILED;
	}
	else
	{
		uint8_t * aligned = (uint8_t*)(loc);
		*aligned = value;
		return SUCCESS;
	}
}
mem_status invert_block(uint32_t * loc, size_t length)
{

}
mem_status write_pattern(uint32_t * loc, size_t length, int8_t seed)
{

}
uint32_t * verify_pattern(uint32_t * loc, size_t length, int8_t seed)
{

}
uint32_t * get_address(uint32_t * offset)
{

}

