/* FreeEMS - the open source engine management system
 *
 * Copyright 2008, 2009 Fred Cooke
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


/** @file miscISRs.c
 * @ingroup interruptHandlers
 *
 * @brief Miscellaneous Interrupt Handlers
 *
 * Various non-descript interrupt handlers that don't really fit anywhere else
 * and aren't big enough to live on their own just yet.
 *
 * @author Fred Cooke
 */


#include "inc/freeEMS.h"
#include "inc/interrupts.h"


/** @brief Unimplemented Interrupt Handler
 *
 * Unimplemented interrupt service routine for calls  we weren't expecting.
 * Currently this simply counts bad calls like any other event type.
 *
 * @author Fred Cooke
 */
void UISR(void){
	/* Increment the unimplemented ISR execution counter */
	Counters.callsToUISRs++;
}


/** @brief Port P pins ISR
 *
 * Interrupt handler for edge events on port P pins. Not currently used.
 *
 * @author Fred Cooke
 */
void PortPISR(void){
	/* Clear all port P flags (we only want one at a time) */
	PIFP = ONES;
	/* Increment the unimplemented ISR execution counter */
	Counters.callsToUISRs++;
}			/* Port P interrupt service routine */


/** @brief Port J pins ISR
 *
 * Interrupt handler for edge events on port J pins. Not currently used.
 *
 * @author Fred Cooke
 */
void PortJISR(void){
	/* Clear all port H flags (we only want one at a time) */
	PIFJ = ONES;
	/* Increment the unimplemented ISR execution counter */
	Counters.callsToUISRs++;
}


/** @brief Port H pins ISR
 *
 * Interrupt handler for edge events on port H pins. Not currently used.
 *
 * @author Fred Cooke
 */
void PortHISR(void)
{
//	// read the interrupt flags to a variable
//	unsigned char portHFlags = PIFH;
//	portHFlags &= 0xF8; // mask out the other bits
//
//	/* Clear all port H flags (we only want one at a time) */
	PIFH = ONES;
//
//	// Toggle a LED so we can see if the code ran
	PORTA ^= 0x80; // Fuel pump pin (A7)
//
	// debounce
	if(portHDebounce == 0){
		portHDebounce = 2;
	}else{
		return;
	}
//
//	// find out which pin triggered it, clear the flag, perform the action.
//	switch(portHFlags)
//	{
//	case 0x80 :	// Increment cylinder count and set port count appropriately.
//		switch (configs.combustionEventsPerEngineCycle) {
//			case 1 :
//				configs.combustionEventsPerEngineCycle = 2;
//				configs.ports = 2;
//				break;
//			case 2 :
//				configs.combustionEventsPerEngineCycle = 3;
//				configs.ports = 3;
//				break;
//			case 3 :
//				configs.combustionEventsPerEngineCycle = 4;
//				configs.ports = 4;
//				break;
//			case 4 :
//				configs.combustionEventsPerEngineCycle = 5;
//				configs.ports = 5;
//				break;
//			case 5 :
//				configs.combustionEventsPerEngineCycle = 6;
//				configs.ports = 6;
//				break;
//			case 6 :
//				configs.combustionEventsPerEngineCycle = 8;
//				configs.ports = 4;
//				break;
//			case 8 :
//				configs.combustionEventsPerEngineCycle = 10;
//				configs.ports = 5;
//				break;
//			case 10 :
//				configs.combustionEventsPerEngineCycle = 12;
//				configs.ports = 6;
//				break;
//			case 12 :
//				configs.combustionEventsPerEngineCycle = 1;
//				configs.ports = 1;
//				break;
//		}
//		break;
//	case 0x40 : // Injection output enable/disable
//		if(coreSettingsA & FUEL_CUT){
//			coreSettingsA &= FUEL_CUT_OFF;
//		}else{
//			coreSettingsA |= FUEL_CUT;
//		}
//		break;
//	case 0x20 : // Ignition output enable/disable
//		if(coreSettingsA & HARD_SPARK_CUT){
//			coreSettingsA &= HARD_SPARK_CUT_OFF;
//		}else{
//			coreSettingsA |= HARD_SPARK_CUT;
//		}
//		break;
//	case 0x10 : // Staged injection enable/disable
//		if(coreSettingsA & STAGED_ON){
//			coreSettingsA &= STAGED_OFF;
//		}else{
//			coreSettingsA |= STAGED_ON;
//		}
//		break;
//	case 0x08 : // Staged injection start sched/fixed
//		if(coreSettingsA & STAGED_START){
//			coreSettingsA &= CLEAR_STAGED_START;
//		}else{
//			coreSettingsA |= STAGED_START;
//		}
//		break;
//	case 0x04 : // Staged injection end sched/fixed
//		if(coreSettingsA & STAGED_END){
//			coreSettingsA &= CLEAR_STAGED_END;
//		}else{
//			coreSettingsA |= STAGED_END;
//		}
//		break;
//	case 0x02 : // free input
//		break;
//	case 0x01 : // free input
//		break;
//	default : // Two or more pressed, nothing to do except wait for another button press
//		break;
//	}
}


/** @brief IRQ/PE1 pin ISR
 *
 * Interrupt handler for edge events on the IRQ/PE1 pin. Not currently used.
 *
 * @author Fred Cooke
 */
void IRQISR(void){
	/* Clear the flag */
	// ?? TODO

	/* Increment the unimplemented ISR execution counter */
	Counters.callsToUISRs++;
}


/** @brief XIRQ/PE0 pin ISR
 *
 * Interrupt handler for edge events on the XIRQ/PE0 pin. Not currently used.
 *
 * @author Fred Cooke
 */
void XIRQISR(void){
	/* Clear the flag */
	// ?? TODO

	/* Increment the unimplemented ISR execution counter */
	Counters.callsToUISRs++;
}


/** @brief Low Voltage Counter
 *
 * Count how often our voltage drops lower than it should without resetting.
 *
 * @author Fred Cooke
 */
void LowVoltageISR(void){
	/* Clear the flag */
	VREGCTRL |= 0x01;

	/* Increment the counter */
	Counters.lowVoltageConditions++;
}
