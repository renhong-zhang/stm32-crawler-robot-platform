/**
 * Project src
 */


#ifndef _MOVEMENT_H
#define _MOVEMENT_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#include "Speed.h"
#include "Angle.h"
#include "Length.h"


typedef struct Movement MovementTypeDef, *pMovementTypeDef;
struct Movement {
// public: 
  AngleTypeDef angle_;
  /**
 * Could be used to Define radius of turning around
 */
  LengthTypeDef distance_;
  SpeedTypeDef speed_;
  float direction_scale_;
};
// public: 





#endif //_MOVEMENT_H
