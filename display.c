#include "pwm_control.h"
#include "hardware/pwm.h"

void init_pwm() {
    gpio_set_function(LED_RED, GPIO_FUNC_PWM);
    gpio_set_function(LED_BLUE, GPIO_FUNC_PWM);
    uint slice_r = pwm_gpio_to_slice_num(LED_RED);
    uint slice_b = pwm_gpio_to_slice_num(LED_BLUE);
    pwm_set_wrap(slice_r, 4095);
    pwm_set_wrap(slice_b, 4095);
    pwm_set_enabled(slice_r, true);
    pwm_set_enabled(slice_b, true);
}

void update_pwm(uint16_t x_value, uint16_t y_value) {
    uint16_t red_duty = abs((int)x_value - 2048) * 2;
    uint16_t blue_duty = abs((int)y_value - 2048) * 2;
    pwm_set_gpio_level(LED_RED, red_duty);
    pwm_set_gpio_level(LED_BLUE, blue_duty);
}

void disable_pwm() {
    pwm_set_gpio_level(LED_RED, 0);
    pwm_set_gpio_level(LED_BLUE, 0);
}
