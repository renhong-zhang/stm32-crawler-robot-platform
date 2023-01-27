/**
 * Project src
 */


#ifndef _SPEED_H
#define _SPEED_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>



typedef struct Speed SpeedTypeDef, *pSpeedTypeDef;
struct Speed {
// public: 
  float cm_s;




};
// public: 

  
/**
 * @param self
 * @param temp_m_s
 */
void Speed__set_m_s_(SpeedTypeDef *self, float temp_m_s);
  
/**
 * @param self
 */
float Speed__get_m_s_(SpeedTypeDef *self);
  
/**
 * @param self
 * @param temp_cm_s
 */
void Speed__set_cm_s_(SpeedTypeDef *self, float temp_cm_s);
  
/**
 * @param self
 */
float Speed__get_cm_s_(SpeedTypeDef *self);

#endif //_SPEED_H