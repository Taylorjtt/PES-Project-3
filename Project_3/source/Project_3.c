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
 * @file Project_3.c
 * @brief
 *
 *  @author John Taylor
 * 	@date Oct 5, 2019
 *
 */
#include <stdio.h>
#ifdef FREEDOM
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MKL25Z4.h"
#include "fsl_debug_console.h"
#endif
#define SEED 0xA
#define LENGTH 16
#include "Pattern/patternGenerator.h"
#include "MemoryTest/MemoryTest.h"


/* TODO: insert other include files here. */

/* TODO: insert other definitions and declarations here. */

/*
 * @brief   Application entry point.
 */

#ifdef FREEDOM
void initFreedom()
{
  	/* Init board hardware. */
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();
  	/* Init FSL debug console. */
    BOARD_InitDebugConsole();

}
#endif
void printArray(uint8_t* array, size_t length)
{
	for(int i = 0; i < length; i++)
	{
		#ifdef FREEDOM
		PRINTF("%X",array[i]);
		#else
		printf("%X",array[i]);
		#endif
	}
	#ifdef FREEDOM
		printf("\n\r");
	#else
		printf("\n\r");
	#endif

}
int main(void) {

#ifdef FREEDOM
	initFreedom();
#endif

	uint32_t* memoryLocation = allocate_words(LENGTH);
	write_pattern(memoryLocation , LENGTH, SEED);
	uint8_t* display = display_memory(memoryLocation, LENGTH);
	printArray(display, LENGTH);
	verify_pattern(memoryLocation, LENGTH, SEED);
	write_memory(memoryLocation, 0xFE);
	write_memory(get_address(memoryLocation, 1), 0xEE);
	display = display_memory(memoryLocation, LENGTH);
	printArray(display, LENGTH);
	verify_pattern(memoryLocation, LENGTH, SEED);
	write_pattern(memoryLocation , LENGTH, SEED);
	verify_pattern(memoryLocation, LENGTH, SEED);
	invert_block(memoryLocation, 4);
	display = display_memory(memoryLocation, LENGTH);
	printArray(display, LENGTH);
	verify_pattern(memoryLocation, LENGTH, SEED);
	invert_block(memoryLocation, 4);
	display = display_memory(memoryLocation, LENGTH);
	printArray(display, LENGTH);
	verify_pattern(memoryLocation, LENGTH, SEED);
	free_words(memoryLocation);

}
