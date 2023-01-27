/**
 * Project src
 */


#ifndef _ANGLE_H
#define _ANGLE_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "math.h"



typedef struct Angle AngleTypeDef, *pAngleTypeDef;
struct Angle {
// public: 
  float degree_;




};
// public: 

  
/**
 * Convert to degree value
 * @param self
 * @param temp_radian
 */
void Angle__set_radian_(AngleTypeDef *self, float temp_radian);
  
/**
 * @param self
 * @param temp_degree
 */
void Angle__set_degree_(AngleTypeDef *self, float temp_degree);
  
/**
 * Convert and return radian value from degree
 * @param self
 */
float Angle__get_radian_(AngleTypeDef *self);
  
/**
 * @param self
 */
float Angle__get_degree_(AngleTypeDef *self);

#endif //_ANGLE_H