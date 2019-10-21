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
#include "Project_3.h"

#ifdef FREEDOM
#define RED_BASE GPIOB
#define RED_PIN 18U

#define GREEN_BASE GPIOB
#define GREEN_PIN 19U

#define BLUE_BASE GPIOD
#define BLUE_PIN 1U

void initFreedom()
{
  	/* Init board hardware. */
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();
  	/* Init FSL debug console. */
    BOARD_InitDebugConsole();
	//initialize the Freedom specific RGB LED object


}
#endif
RGBLEDHandle led;
LoggerHandle logger;


int main(void)
{
#ifdef FREEDOM
	initFreedom();
	led = malloc(sizeof(RGBLEDObject));
	led = RGBLED_Constructor((void*) led, sizeof(RGBLEDObject), RED_BASE, RED_PIN, GREEN_BASE, GREEN_PIN, BLUE_BASE, BLUE_PIN);
#else
	led = malloc(sizeof(RGBLEDObject));
	led = RGBLED_Constructor((void*) led, sizeof(RGBLEDObject));
#endif




	RGBLED_set(led, false, false, true);
	logger = malloc(sizeof(LOGGERObject));
	logger = Logger_Constructor((void*)logger, sizeof(LoggerHandle));
	Logger_enable(logger);

	Logger_logString(logger, "Allocating 16 Bytes");
	//Allocate 16 bytes
	uint32_t* memoryLocation = allocate_words(LENGTH);

	Logger_logString(logger, "Writing a memory pattern with seed 0xA");
	write_pattern(memoryLocation , LENGTH, SEED);

	//Display that region’s memory pattern
	display_memory(memoryLocation, LENGTH);


	//Verify that region’s memory pattern (should pass)
	Logger_logString(logger, "Verifying Pattern (Should Pass)");
	verify_pattern(memoryLocation, LENGTH, SEED);

	//Write 0xFFEE to a position within that region (location + some offset you select)
	Logger_logString(logger, "Writing 0xFFEE to the beginning of the chunk");
	write_memory(memoryLocation, 0xFE);
	write_memory(get_address(memoryLocation, 1), 0xEE);

	//Display that region’s memory pattern
	display_memory(memoryLocation, LENGTH);

	//Verify the memory pattern again (should error)
	Logger_logString(logger, "Verifying Pattern (should fail)");
	verify_pattern(memoryLocation, LENGTH, SEED);

	//Write a memory pattern to the region using the same seed as before
	Logger_logString(logger, "Writing a memory pattern with seed 0xA");
	write_pattern(memoryLocation , LENGTH, SEED);

	//Display that region’s memory pattern
	display_memory(memoryLocation, LENGTH);


	//Verify that memory pattern again (should pass)
	Logger_logString(logger, "Verifying Pattern (Should Pass)");
	verify_pattern(memoryLocation, LENGTH, SEED);

	//Invert 4 bytes in the region (location + some offset)
	Logger_logString(logger, "Inverting the first four bytes");
	invert_block(memoryLocation, 4);

	//Display that region’s memory pattern
	display_memory(memoryLocation, LENGTH);


	//Verify the memory pattern again (should error)
	Logger_logString(logger, "Verifying Pattern (Should Fail)");
	verify_pattern(memoryLocation, LENGTH, SEED);

	//Invert those 4 bytes again in the LMA region (location + some offset)
	Logger_logString(logger, "Inverting the bytes again");
	invert_block(memoryLocation, 4);

	//Display that region’s memory pattern
	display_memory(memoryLocation, LENGTH);


	//Verify that memory pattern again (should pass)
	Logger_logString(logger, "Verifying Pattern (Should Pass)");
	verify_pattern(memoryLocation, LENGTH, SEED);

	//Free the 16 byte allocated region
	Logger_logString(logger, "Freeing the memory");
	free_words(memoryLocation);

}
