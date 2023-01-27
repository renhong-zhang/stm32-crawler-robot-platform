/**
 * Project src
 */


#include "DataType/Length.h"

/**
 * Length implementation
 * 
 * Due to the accuracy of our machine, the unit to store the Length is cm
 */


/**
 * convert centimeter to meter
 * @param self
 * @return float
 */
float Length__get_m_(LengthTypeDef *self) {

  return (float)((self->cm_)/100.0);
}

/**
 * Convert meter to centimeter
 * @param self
 * @param temp_m
 */
void Length__set_m_(LengthTypeDef *self, float temp_m) {
  self->cm_ = (float)(temp_m * 100);

}

/**
 * @param self
 * @return float
 */
float Length__get_cm_(LengthTypeDef *self) {

  return (float)(self->cm_);
}

/**
 * @param self
 * @param temp_cm
 */
void Length__set_cm_(LengthTypeDef *self, float temp_cm) {
  self->cm_ = (float)(temp_cm);

}
