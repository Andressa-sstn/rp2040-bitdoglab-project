#ifndef SSD1306_H
#define SSD1306_H

#include "pico/stdlib.h"
#include "hardware/i2c.h"

typedef struct {
    i2c_inst_t *i2c;
    uint8_t address;
    uint8_t width;
    uint8_t height;
} ssd1306_t;

void ssd1306_init(ssd1306_t *display, uint8_t width, uint8_t height, i2c_inst_t *i2c, uint8_t address);
void ssd1306_clear(ssd1306_t *display);
void ssd1306_draw_rect(ssd1306_t *display, int x, int y, int w, int h);
void ssd1306_update(ssd1306_t *display);

#endif
