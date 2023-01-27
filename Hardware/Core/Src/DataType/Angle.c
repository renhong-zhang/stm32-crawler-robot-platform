/**
 * Project src
 */


#include "DataType/Angle.h"

/**
 * Angle implementation
 * 
 * only store degree, but could be set/get radian value
 */


/**
 * Convert to degree value
 * @param self
 * @param temp_radian
 */
void Angle__set_radian_(AngleTypeDef *self, float temp_radian) {
  self->degree_ = (float)((temp_radian * 180) / M_PI);

}

/**
 * @param self
 * @param temp_degree
 */
void Angle__set_degree_(AngleTypeDef *self, float temp_degree) {
  self->degree_ = (float)temp_degree;

}

/**
 * Convert and return radian value from degree
 * @param self
 * @return float
 */
float Angle__get_radian_(AngleTypeDef *self) {

  return (float)(((self->degree_) * M_PI) / 180.0);
}

/**
 * @param self
 * @return float
 */
float Angle__get_degree_(AngleTypeDef *self) {
float temp_degree = (float)(self->degree_);
  return temp_degree;
}
