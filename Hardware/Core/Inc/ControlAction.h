/**
 * Project src
 */


#ifndef _CONTROLACTION_H
#define _CONTROLACTION_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>



typedef enum ControlAction ControlActionTypeDef, *pControlActionTypeDef;
enum ControlAction { ControlAction__stop_ = 1, ControlAction__move_ = 2, ControlAction__write_length__ = 7};

#endif //_CONTROLACTION_H
