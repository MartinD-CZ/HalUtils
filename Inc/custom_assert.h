/* mal_assert.h
 *
 *  Created on: Jan 22, 2022
 *  Author: Martin Danek, martin@embedblog.eu
 */

#ifndef CUSTOM_ASSERT_H_
#define CUSTOM_ASSERT_H_

#include <stdint.h>

#if defined DISABLE_ASSERT
#define ASSERT_ALWAYS()						(void)(expr)
#define ASSERT(expr)						(void)(expr)
#define ASSERT_WITH_RETURN(expr)			(void)(expr)
#define ASSERT_WITH_RETURN_VALUE(expr, val)	(void)(expr)
#else
#define ASSERT_ALWAYS()						do {custom_assert(__FILENAME__, __LINE__);} while(0)
#define ASSERT(expr)						do {if(!(expr)) custom_assert(__FILENAME__, __LINE__);} while(0)
#define ASSERT_WITH_RETURN(expr)			do {if(!(expr)) {custom_assert(__FILENAME__, __LINE__); return;}} while(0)
#define ASSERT_WITH_RETURN_VALUE(expr, val)	do {if(!(expr)) {custom_assert(__FILENAME__, __LINE__); return val;}} while(0)

void custom_assert(const char* file, uint32_t line);

template <typename T> inline bool isValueBetween(T value, T min, T max)
{
	return ((value >= min) && (value <= max));
}

#endif /* CUSTOM_ASSERT_H_ */
