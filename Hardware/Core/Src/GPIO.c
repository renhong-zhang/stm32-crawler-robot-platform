/**
 * Project src
 */


#include "GPIO.h"

/**
 * GPIO implementation
 */


/**
 * @param self
 */
void GPIO__Init(GPIOTypeDef *self) {
  GPIO_InitTypeDef GPIO_InitStruct = { 0 };


  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOE_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
//  __HAL_RCC_GPIOF_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  // HAL_GPIO_WritePin((self->peripheral_), (self->pin_), GPIO_PIN_RESET);

  /*Configure GPIO pin : PA1 */
  GPIO_InitStruct.Pin = (self->pin_);
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init((self->peripheral_), &GPIO_InitStruct);


  GPIO__set_state_bool_(self, false);

}

/**
 * @param self
 * @param temp_state_bool
 */
void GPIO__set_state_bool_(GPIOTypeDef *self, bool temp_state_bool) {
if (temp_state_bool) {
  HAL_GPIO_WritePin((self->peripheral_), (self->pin_), GPIO_PIN_SET);
  (self->state_bool_) = true;
  (self->state_) = GPIO_PIN_SET;
} else {
  HAL_GPIO_WritePin((self->peripheral_), (self->pin_), GPIO_PIN_RESET);
  (self->state_bool_) = false;
  (self->state_) = GPIO_PIN_RESET;
}

}

/**
 * @param self
 * @return bool
 */
bool GPIO__get_state_bool_(GPIOTypeDef *self) {
  if (HAL_GPIO_ReadPin((self->peripheral_), (self->pin_)) == GPIO_PIN_SET) {
    (self->state_bool_) = true;
    (self->state_) = GPIO_PIN_SET;
  } else {
    (self->state_bool_) = false;
    (self->state_) = GPIO_PIN_RESET;
  }
  return false;
}
