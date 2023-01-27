/**
 * Project src
 */

#include "MotorController.h"

/**
 * MotorController implementation
 */

/**
 * @param self
 */
void MotorController__Init(MotorControllerTypeDef *self) {
  PWM__Init(&(self->pwm_ENA_));
  PWM__Init(&(self->pwm_ENB_));
  GPIO__Init(&(self->gpio_EN1_));
  GPIO__Init(&(self->gpio_EN2_));
  GPIO__Init(&(self->gpio_EN3_));
  GPIO__Init(&(self->gpio_EN4_));

}

/**
 * @param self
 */
void MotorController__Move(MotorControllerTypeDef *self) {
  // A,1,2 for L;
  // B,3,4 for R


  float move_velocity_center_mod = Speed__get_cm_s_(
      &((self->movement_).speed_));  // |Vc|
  float move_distance_center_mod = Length__get_cm_(
      &((self->movement_).distance_));  // |D|
  float mov_direction_scale = ((self->movement_).direction_scale_);  // dir
  float move_angle = Angle__get_radian_(&((self->movement_).angle_));
  float width = 37.5 / 2;  // distance between center of wheels: cm
  float width_div2 = width / 2;

  float velocity_R;
  float velocity_L;
  float duty_cycle_R;
  float duty_cycle_L;

  // Store the state from calculation
  bool temp_IN_state_R[2], temp_IN_state_L[2];




  move_velocity_center_mod = fabs(move_velocity_center_mod);  // |Vc|
  move_distance_center_mod = fabs(move_distance_center_mod);  // |D|

  // Get Velocity of Each Side of Robot
  velocity_L = (move_velocity_center_mod / move_distance_center_mod)
      * ((move_distance_center_mod * mov_direction_scale)
          - (width_div2 * move_angle));
  velocity_R = (move_velocity_center_mod / move_distance_center_mod)
      * ((move_distance_center_mod * mov_direction_scale)
          + (width_div2 * move_angle));


  // Get DutyCycle of Both Side input to the Driver
  duty_cycle_L = ConvertVelocityToDutyCyclePercent(velocity_L);
  duty_cycle_R = ConvertVelocityToDutyCyclePercent(velocity_R);


  // Get the State of each Pin
  ConvertVelocityTopINStateBool(velocity_L, &(temp_IN_state_L[0]));
  ConvertVelocityTopINStateBool(velocity_R, &(temp_IN_state_R[0]));


  // Set State of each Pin/Channel
  PWM__set_duty_cycle_percent_(&(self->pwm_ENA_), duty_cycle_L);
  PWM__set_duty_cycle_percent_(&(self->pwm_ENB_), duty_cycle_R);
  GPIO__set_state_bool_(&(self->gpio_EN1_), temp_IN_state_L[0]);
  GPIO__set_state_bool_(&(self->gpio_EN2_), temp_IN_state_L[1]);
  GPIO__set_state_bool_(&(self->gpio_EN3_), temp_IN_state_R[0]);
  GPIO__set_state_bool_(&(self->gpio_EN4_), temp_IN_state_R[1]);



}

// Used to Calculate the DutyCycle from Velocity as input
 static float ConvertVelocityToDutyCyclePercent(float temp_velocity) {
    float angular_velocity_x;  // W_x(t)
    float wheel_radius = 2.6;       // r_wheel
    float encoder_accuracy = 780;   // Accuracy
    float velocity_x;         // V_x(t)

    float voltage_x;          // volx

    float k_encoder_x = 185;
    float b_encoder_x = -450;

    float duty_cycle_x;  // DCx


    float max_voltage_x = 12;  // Vmax

    float max_duty_cycle_x = 100;  // DCmax
    velocity_x = fabs(temp_velocity);
    angular_velocity_x = velocity_x / wheel_radius;

    voltage_x = (angular_velocity_x * (encoder_accuracy / (2 * M_PI)) - b_encoder_x) / k_encoder_x;

    duty_cycle_x = (max_duty_cycle_x / max_voltage_x) * voltage_x;
    return duty_cycle_x;
  }

static void ConvertVelocityTopINStateBool(float temp_velocity, bool *temp_IN_state_x) {
  if (temp_velocity > 0) {
    temp_IN_state_x[0] = false;
    temp_IN_state_x[1] = true;
  } else if (temp_velocity < 0) {
    temp_IN_state_x[0] = true;
    temp_IN_state_x[1] = false;
  } else {
    temp_IN_state_x[0] = false;
    temp_IN_state_x[1] = false;
  }

}
