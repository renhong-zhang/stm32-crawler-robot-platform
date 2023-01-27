/**
 * Project src
 */


#ifndef _PWM_H
#define _PWM_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>



#ifndef _INCLUDE_STM32H7XX_HAL_H
#define _INCLUDE_STM32H7XX_HAL_H
#include "stm32h7xx_hal.h"
#endif // _INCLUDE_STM32H7XX_HAL_H


typedef struct PWM PWMTypeDef, *pPWMTypeDef;
struct PWM {
// public: 
  TIM_TypeDef * peripheral_;
  HAL_TIM_ActiveChannel channel_;
  float frequency_;
  uint32_t duty_cycle_period_;





// private: 
  TIM_HandleTypeDef handle_;
  uint32_t period_;
  uint32_t prescalar_;
};
// public: 




  
/**
 * @param self
 */
void PWM__Init(PWMTypeDef *self);
  
/**
 * @param self
 * @param temp_duty_cycle_percent
 */
void PWM__set_duty_cycle_percent_(PWMTypeDef *self, float temp_duty_cycle_percent);
  
/**
 * @param self
 */
float PWM__get_duty_cycle_percent_(PWMTypeDef *self);
  
/**
 * @param self
 * @param temp_duty_cycle_period
 */
void PWM__set_duty_cycle_period_(PWMTypeDef *self, uint32_t temp_duty_cycle_period);
  
/**
 * @param self
 */
uint32_t PWM__get_duty_cycle_period_(PWMTypeDef *self);
// private: 




#endif //_PWM_H
