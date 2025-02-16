#include "display.h"
#include "ssd1306.h"
#include "hardware/i2c.h"

ssd1306_t display;

void init_display() {
    i2c_init(i2c_default, 400000);
    gpio_set_function(I2C_SDA, GPIO_FUNC_I2C);
    gpio_set_function(I2C_SCL, GPIO_FUNC_I2C);
    gpio_pull_up(I2C_SDA);
    gpio_pull_up(I2C_SCL);
    ssd1306_init(&display, 128, 64, i2c_default, 0x3C);
    ssd1306_clear(&display);
}

void update_display(uint16_t x_value, uint16_t y_value, int border_style) {
    int square_x = (x_value * 112) / 4095 + 8;
    int square_y = (y_value * 48) / 4095 + 8;
    
    ssd1306_clear(&display);
    ssd1306_draw_rect(&display, square_x, square_y, 8, 8);
    
    if (border_style == 1) {
        ssd1306_draw_rect(&display, 0, 0, 128, 64);
    } else if (border_style == 2) {
        ssd1306_draw_rect(&display, 2, 2, 124, 60);
    }
    
    ssd1306_update(&display);
}
