/**
 * Project Untitled
 */


#include "Crawler_Robot_Controller_Model.h"

//` PRIVITE INCLUDE 
#include "rtwtypes.h"
#include "builtin_typeid_types.h"



/**
 * Crawler_Robot_Controller_Model implementation
 */


/**
 * @param self
 */
void Crawler_Robot_Controller_Model__Step(Crawler_Robot_Controller_ModelTypeDef *self) {
static boolean_T OverrunFlag = false;

  /* Disable interrupts here */

  /* Check for overrun */
  if (OverrunFlag) {
    return;
  }

  OverrunFlag = true;

  /* Save FPU context here (if necessary) */
  /* Re-enable timer or interrupt here */
  /* Set model inputs here */

  /* Step the model */
  Crawler_Robot_Controller_Model_step((self->temp_model_),
    &(self->in_), &(self->out_));

  /* Get model outputs here */

  /* Indicate task complete */
  OverrunFlag = false;

  /* Disable interrupts here */
  /* Restore FPU context here (if necessary) */
  /* Enable interrupts here */

}

/**
 * @param self
 */
void Crawler_Robot_Controller_Model__Init(Crawler_Robot_Controller_ModelTypeDef *self) {



  (self->model_pointer_) = &(self->model_);

  //` Similar to Main function
  (self->temp_model_) = (self->model_pointer_);
  /* Pack model data into RTM */
  ((self->temp_model_)->dwork) = &(self->state_);
  /* Initialize model */
  Crawler_Robot_Controller_Model_initialize((self->temp_model_),
    &(self->in_), &(self->out_));

  //` Unknown
  fflush((NULL));
}

/**
 * @param self
 */
void Crawler_Robot_Controller_Model__Terminate(Crawler_Robot_Controller_ModelTypeDef *self) {
  Crawler_Robot_Controller_Model_terminate((self->temp_model_));

}
