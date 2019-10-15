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
 * @file logger.c
 * @brief Cross platform Logger
 *
 *  @author John Taylor
 * 	@date Aug 11, 2019
 *
 */

#ifndef LOGGER_LOGGER_H_
#define LOGGER_LOGGER_H_
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#ifdef FREEDOM
#include "fsl_debug_console.h"
#endif
typedef enum {DISABLED,ENABLED}LOGGER_STATUS;

typedef struct LOGGER_OBJ
{
	LOGGER_STATUS status;
}LOGGERObject;

typedef struct LOGGER_OBJ *LoggerHandle;

LoggerHandle Logger_Constructor(void *pmemory, const size_t numbytes);
void Logger_enable(LoggerHandle handle);
void Logger_disable(LoggerHandle handle);
LOGGER_STATUS Logger_status(LoggerHandle handle);
void Logger_logData(LoggerHandle handle, uint8_t* loc, size_t length);
void Logger_logString(LoggerHandle handle, const char * string);
void Logger_logInt(LoggerHandle handle, uint8_t num);

#endif /* LOGGER_LOGGER_H_ */
