/**
 * Project src
 */


#include "DataType/Speed.h"

/**
 * Speed implementation
 */


/**
 * @param self
 * @param temp_m_s
 */
void Speed__set_m_s_(SpeedTypeDef *self, float temp_m_s) {
  self->cm_s = (float)(temp_m_s * 100);

}

/**
 * @param self
 * @return float
 */
float Speed__get_m_s_(SpeedTypeDef *self) {

  return (float)((self->cm_s)/100.0);
}

/**
 * @param self
 * @param temp_cm_s
 */
void Speed__set_cm_s_(SpeedTypeDef *self, float temp_cm_s) {
  self->cm_s = (float)(temp_cm_s);

}

/**
 * @param self
 * @return float
 */
float Speed__get_cm_s_(SpeedTypeDef *self) {

  return (float)(self->cm_s);
}
