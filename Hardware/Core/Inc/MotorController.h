/**
 * Project src
 */


#ifndef _MOTORCONTROLLER_H
#define _MOTORCONTROLLER_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>


#ifndef _INCLUDE_STM32H7XX_HAL_H
#define _INCLUDE_STM32H7XX_HAL_H
#include "stm32h7xx_hal.h"
#endif // _INCLUDE_STM32H7XX_HAL_H
#include "DataType/Movement.h"
#include "GPIO.h"
#include "PWM.h"


typedef struct MotorController MotorControllerTypeDef, *pMotorControllerTypeDef;
struct MotorController {
// public: 
  PWMTypeDef pwm_ENA_;
  PWMTypeDef pwm_ENB_;
  GPIOTypeDef gpio_EN1_;
  GPIOTypeDef gpio_EN2_;
  GPIOTypeDef gpio_EN3_;
  GPIOTypeDef gpio_EN4_;
  MovementTypeDef movement_;


};
// public: 







  
/**
 * @param self
 */
void MotorController__Init(MotorControllerTypeDef *self);
  
/**
 * @param self
 */
void MotorController__Move(MotorControllerTypeDef *self);

static float ConvertVelocityToDutyCyclePercent(float);
static void ConvertVelocityTopINStateBool(float , bool *) ;

#endif //_MOTORCONTROLLER_H
