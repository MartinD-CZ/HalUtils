/* custom_log.h
 *
 * Created on: 16. 3. 2022
 * Author: Martin Danek, martin@embedblog.eu
 */

#ifndef CUSTOM_LOG_H_
#define CUSTOM_LOG_H_

#include <stddef.h>

enum class DebugLevel
{
	VERBOSE = 0,
	DBG = 1,
	INFO = 2,
	WARNING = 3,
	ERROR = 4
};

#ifndef LOG_LEVEL
#define LOG_LEVEL		0		//sets the minimal level of log, which will be outputted
#endif

void customLog(DebugLevel debugLevel, const char* msg, ...);

//these two functions must be iomplemented by the user:
void _log_send(const char* msg, size_t len);
bool _log_isReady();

#if (LOG_LEVEL < 1)
#define LOGV(x)				customLog(DebugLevel::VERBOSE, x)
#else
#define LOGV(x)				(void)(x)
#endif

#if (LOG_LEVEL < 2)
#define LOGD(x)				customLog(DebugLevel::DBG, x)
#else
#define LOGD(x)				(void)(x)
#endif

#if (LOG_LEVEL < 3)
#define LOGI(x)				customLog(DebugLevel::INFO, x)
#else
#define LOGI(x)				(void)(x)
#endif

#if (LOG_LEVEL < 4)
#define LOGW(x)				customLog(DebugLevel::WARNING, x)
#else
#define LOGW(x)				(void)(x)
#endif

#if (LOG_LEVEL < 5)
#define LOGE(x)				customLog(DebugLevel::ERROR, x)
#else
#define LOGE(x)				(void)(x)
#endif

#endif /* CUSTOM_LOG_H_ */
