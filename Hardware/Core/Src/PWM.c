/**
 * Project src
 */


#include "PWM.h"

/**
 * PWM implementation
 */


/**
 * @param self
 */
void PWM__Init(PWMTypeDef *self) {
  /* USER CODE BEGIN TIM2_Init 0 */
  // input: TIM_HandleTypeDef *temp_htim, TIM_TypeDef *Temp_TIM, HAL_TIM_ActiveChannel temp_channel, float temp_freq

  // `Calculate frequency
  uint32_t base_clock_freq = 25000000;
  (self->prescalar_) = (base_clock_freq / 1000000) - 1;
  (self->period_) = (uint32_t)(((base_clock_freq / ((self->prescalar_) + 1))/ (self->frequency_)) - 1);
  /* USER CODE END TIM2_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_OC_InitTypeDef sConfigOC = {0};

  /* USER CODE BEGIN TIM2_Init 1 */
  // 99,999: 25e6/1e5=250Hz
  /* USER CODE END TIM2_Init 1 */
  (self->handle_).Instance = (self->peripheral_);//! Handle
  (self->handle_).Init.Prescaler = (self->prescalar_);
  (self->handle_).Init.CounterMode = TIM_COUNTERMODE_UP;
  (self->handle_).Init.Period = (self->period_);//! freq: 50Hz
  (self->handle_).Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  (self->handle_).Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&(self->handle_)) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&(self->handle_), &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_Init(&(self->handle_)) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&(self->handle_), &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 0;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  if (HAL_TIM_PWM_ConfigChannel(&(self->handle_), &sConfigOC, (self->channel_)) != HAL_OK)//! Channel
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */
  HAL_TIM_MspPostInit(&(self->handle_));

  // ! start move here
  HAL_TIM_PWM_Start(&(self->handle_), (self->channel_));
}

/**
 * @param self
 * @param temp_duty_cycle_percent
 */
void PWM__set_duty_cycle_percent_(PWMTypeDef *self, float temp_duty_cycle_percent) {
  if (temp_duty_cycle_percent < 0.0){
    temp_duty_cycle_percent = 0.0;
  } else if (temp_duty_cycle_percent > 100.0){
    temp_duty_cycle_percent = 100.0;
  }

  uint32_t temp_duty_cycle_period = (uint32_t)((temp_duty_cycle_percent / 100.0) * (self->period_ + 1)) - 1;
  PWM__set_duty_cycle_period_(self, temp_duty_cycle_period);

}

/**
 * @param self
 * @return float
 */
float PWM__get_duty_cycle_percent_(PWMTypeDef *self) {
  return (((float)(PWM__get_duty_cycle_period_(self) + 1) / (float)((self->period_) + 1)) * 100.0);
}

/**
 * @param self
 * @param temp_duty_cycle_period
 */
void PWM__set_duty_cycle_period_(PWMTypeDef *self, uint32_t temp_duty_cycle_period) {
  (self->duty_cycle_period_) = temp_duty_cycle_period;
  __HAL_TIM_SET_COMPARE(&(self->handle_), (self->channel_), (self->duty_cycle_period_));
}

/**
 * @param self
 * @return uint32_t
 */
uint32_t PWM__get_duty_cycle_period_(PWMTypeDef *self) {
  (self->duty_cycle_period_) = __HAL_TIM_GET_COMPARE(&(self->handle_), (self->channel_));
  return (self->duty_cycle_period_);
}
