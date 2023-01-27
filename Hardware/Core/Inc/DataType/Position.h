/**
 * Project src
 */


#ifndef _POSITION_H
#define _POSITION_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#include "Length.h"
#include "Angle.h"


typedef struct Position PositionTypeDef, *pPositionTypeDef;
struct Position {
// public: 
  LengthTypeDef radius_;
  AngleTypeDef angle_;
  LengthTypeDef height_;
};
// public: 




#endif //_POSITION_H