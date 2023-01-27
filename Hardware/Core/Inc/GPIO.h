/**
 * Project src
 */


#ifndef _GPIO_H
#define _GPIO_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#ifndef _INCLUDE_STM32H7XX_HAL_H
#define _INCLUDE_STM32H7XX_HAL_H
#include "stm32h7xx_hal.h"
#endif // _INCLUDE_STM32H7XX_HAL_H


typedef struct GPIO GPIOTypeDef, *pGPIOTypeDef;
struct GPIO {
// public: 
  GPIO_TypeDef *peripheral_;
  uint16_t pin_;
  bool state_bool_;



// private: 
  GPIO_PinState state_;
};
// public: 



  
/**
 * @param self
 */
void GPIO__Init(GPIOTypeDef *self);
  
/**
 * @param self
 * @param temp_state_bool
 */
void GPIO__set_state_bool_(GPIOTypeDef *self, bool temp_state_bool);
  
/**
 * @param self
 */
bool GPIO__get_state_bool_(GPIOTypeDef *self);
// private: 


#endif //_GPIO_H
