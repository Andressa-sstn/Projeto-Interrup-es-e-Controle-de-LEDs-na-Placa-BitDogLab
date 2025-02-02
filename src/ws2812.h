#ifndef WS2812_H
#define WS2812_H

#include <stdint.h>

void init_ws2812(uint pin);
void set_pixel(int index, uint32_t color);

#endif
