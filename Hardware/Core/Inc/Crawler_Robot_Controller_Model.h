/**
 * Project Untitled
 */


#ifndef _CRAWLER_ROBOT_CONTROLLER_MODEL_H
#define _CRAWLER_ROBOT_CONTROLLER_MODEL_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#ifndef _INCLUDE_SIMULINK__CRAWLER_ROBOT_CONTROLLER_MODEL_H
#define _INCLUDE_SIMULINK__CRAWLER_ROBOT_CONTROLLER_MODEL_H
#include "Simulink__Crawler_Robot_Controller_Model.h" /* Model's header file */
#endif // _INCLUDE_SIMULINK__CRAWLER_ROBOT_CONTROLLER_MODEL_H


typedef struct Crawler_Robot_Controller_Model Crawler_Robot_Controller_ModelTypeDef, *pCrawler_Robot_Controller_ModelTypeDef;
struct Crawler_Robot_Controller_Model {
// public: 
  Crawler_Robot_Controller_Model__RT_MODEL model_;
  Crawler_Robot_Controller_Model__RT_MODEL *model_pointer_;    /* Real-time model */
  Crawler_Robot_Controller_Model__DW state_;/* Observable states */
  Crawler_Robot_Controller_Model__ExtU in_;/* External inputs */
  Crawler_Robot_Controller_Model__ExtY out_;/* External outputs */


//` Temp value
Crawler_Robot_Controller_Model__RT_MODEL *temp_model_ ;

};
// public: 
  
/**
 * @param self
 */
void Crawler_Robot_Controller_Model__Step(Crawler_Robot_Controller_ModelTypeDef *self);
  
/**
 * @param self
 */
void Crawler_Robot_Controller_Model__Init(Crawler_Robot_Controller_ModelTypeDef *self);
  
/**
 * @param self
 */
void Crawler_Robot_Controller_Model__Terminate(Crawler_Robot_Controller_ModelTypeDef *self);

#endif //_CRAWLER_ROBOT_CONTROLLER_MODEL_H
