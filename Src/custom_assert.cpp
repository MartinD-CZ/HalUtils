/* mal_assert.cpp
 *
 *  Created on: Jan 22, 2022
 *  Author: Martin Danek, martin@embedblog.eu
 */

#include "hal_inc.h"

__WEAK void custom_assert(const char* file, uint32_t line)
{
	__asm("bkpt 0");		//breakpoint instruction
}

