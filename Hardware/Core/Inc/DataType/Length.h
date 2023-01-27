/**
 * Project src
 */


#ifndef _LENGTH_H
#define _LENGTH_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>



typedef struct Length LengthTypeDef, *pLengthTypeDef;
struct Length {
// public: 
  float cm_;




};
// public: 

  
/**
 * convert centimeter to meter
 * @param self
 */
float Length__get_m_(LengthTypeDef *self);
  
/**
 * Convert meter to centimeter
 * @param self
 * @param temp_m
 */
void Length__set_m_(LengthTypeDef *self, float temp_m);
  
/**
 * @param self
 */
float Length__get_cm_(LengthTypeDef *self);
  
/**
 * @param self
 * @param temp_cm
 */
void Length__set_cm_(LengthTypeDef *self, float temp_cm);

#endif //_LENGTH_H