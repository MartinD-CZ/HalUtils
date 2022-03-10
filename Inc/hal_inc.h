/* hal_inc.h
 *
 * Created on: Mar 7, 2022
 * Author: Martin Danek, martin@embedblog.eu
 */

#ifndef HAL_INC_H_
#define HAL_INC_H_

#include <stdint.h>
#include <stdio.h>

#if defined(STM32G0)
#include "stm32g0xx_hal.h"
#elif defined(STM32G4)
#include "stm32g4xx_hal.h"
#endif



#endif /* HAL_INC_H_ */
