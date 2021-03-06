/* FreeEMS - the open source engine management system
 *
 * Copyright 2010 Fred Cooke
 *
 * This file is part of the FreeEMS project.
 *
 * FreeEMS software is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * FreeEMS software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with any FreeEMS software.  If not, see http://www.gnu.org/licenses/
 *
 * We ask that if you make any changes to this file you email them upstream to
 * us at admin(at)diyefi(dot)org or, even better, fork the code on github.com!
 *
 * Thank you for choosing FreeEMS to run your engine!
 */

/** @page generalStrategies General Strategies
 *
 * This page exists to document general coding strategies used in this
 * firmware. Each item should contain a title, description, situations
 * it is useful in and somewhere you can see an example of it in use.
 *
 * Reading/Writing from/to a specific page :
 *
 * Save the current page value to a variable, change the page value to the desired one, read or write the paged memory, change the page back and return the value
 *
 * This is applicable to all three available memory types: Flash, RAM and EEPROM.
 *
 * Examples of its use can be found in flashWrite.c
 *
 * @todo TODO TBC (other strategies)
 */

/** @file strategies.h
 *
 * @ingroup doxygenDocFiles
 * @brief Doxygen General Strategies page definition
 */
