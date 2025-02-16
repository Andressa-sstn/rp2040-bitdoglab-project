#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/adc.h"
#include "hardware/pwm.h"
#include "hardware/i2c.h"
#include "joystick.h"
#include "display.h"
#include "pwm_control.h"

#define LED_GREEN 12
#define JOYSTICK_BUTTON 22
#define BUTTON_A 5

volatile bool led_state = false;
volatile bool pwm_enabled = true;
volatile int border_style = 0;

void joystick_button_callback(uint gpio, uint32_t events) {
    led_state = !led_state;
    gpio_put(LED_GREEN, led_state);
    border_style = (border_style + 1) % 3;
}

void button_a_callback(uint gpio, uint32_t events) {
    pwm_enabled = !pwm_enabled;
    if (!pwm_enabled) {
        disable_pwm();
    }
}

int main() {
    stdio_init_all();
    init_joystick();
    init_display();
    init_pwm();
    
    gpio_init(LED_GREEN);
    gpio_set_dir(LED_GREEN, GPIO_OUT);
    gpio_init(JOYSTICK_BUTTON);
    gpio_set_dir(JOYSTICK_BUTTON, GPIO_IN);
    gpio_pull_up(JOYSTICK_BUTTON);
    gpio_set_irq_enabled_with_callback(JOYSTICK_BUTTON, GPIO_IRQ_EDGE_FALL, true, &joystick_button_callback);
    gpio_init(BUTTON_A);
    gpio_set_dir(BUTTON_A, GPIO_IN);
    gpio_pull_up(BUTTON_A);
    gpio_set_irq_enabled_with_callback(BUTTON_A, GPIO_IRQ_EDGE_FALL, true, &button_a_callback);

    while (true) {
        uint16_t x_value, y_value;
        read_joystick(&x_value, &y_value);
        
        if (pwm_enabled) {
            update_pwm(x_value, y_value);
        }
        
        update_display(x_value, y_value, border_style);
        sleep_ms(50);
    }
}
