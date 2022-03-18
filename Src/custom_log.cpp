/* custom_log.cpp
 *
 * Created on: 16. 3. 2022
 * Author: Martin Danek, martin@embedblog.eu
 */

#include "custom_log.h"

#include "hal_inc.h"
#include "custom_assert.h"

#include <stdio.h>

#ifndef LOG_BUF_SIZE
#define LOG_BUF_SIZE		128
#endif

#ifndef LOG_TIMEOUT
#define LOG_TIMEOUT			250
#endif

static const char logChr[] = {'V', 'D', 'I', 'W', 'E'};
static char buf[LOG_BUF_SIZE];

void customLog(DebugLevel debugLevel, const char* msg, ...)
{
	auto start = HAL_GetTick();
	while (!_log_isReady())
		ASSERT_WITH_RETURN(HAL_GetTick() - start < LOG_TIMEOUT);

	auto len = snprintf(buf, LOG_BUF_SIZE, "%lu %c: %s", start, logChr[(size_t)debugLevel], msg);

	_log_send(buf, len);
}

__WEAK void _log_send(const char* msg, size_t len)
{
	__asm("bkpt 0");
}

__WEAK bool _log_isReady()
{
	__asm("bkpt 0");
	return false;
}


