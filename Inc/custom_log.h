/* custom_log.h
 *
 * Created on: 16. 3. 2022
 * Author: Martin Danek, martin@embedblog.eu
 */

#ifndef CUSTOM_LOG_H_
#define CUSTOM_LOG_H_

enum DebugLevel
{
	VERBOSE = 0/*,
	DEBUG = 1*/,
	INFO = 2,
	WARNING = 3,
	ERROR = 4
};

#ifndef LOG_LEVEL
#define LOG_LEVEL		0
#endif

void customLog(DebugLevel debugLevel, const char* msg, ...);

#if (LOG_LEVEL < 1)
#define LOGV(x)				customLog(VERBOSE, x)
#else
#define LOGV(x)				(void)(x)
#endif

#define LOGD
#define LOGI
#define LOGW
#define LOGE

#endif /* CUSTOM_LOG_H_ */
