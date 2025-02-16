#ifndef PWM_CONTROL_H
#define PWM_CONTROL_H

#include "pico/stdlib.h"

#define LED_RED 11
#define LED_BLUE 13

void init_pwm();
void update_pwm(uint16_t x_value, uint16_t y_value);
void disable_pwm();

#endif
