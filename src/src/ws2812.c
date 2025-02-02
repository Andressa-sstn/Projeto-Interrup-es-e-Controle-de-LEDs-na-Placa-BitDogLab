#include "ws2812.h"
#include "pico/stdlib.h"

static uint ws2812_pin;

void init_ws2812(uint pin) {
    ws2812_pin = pin;
    gpio_init(ws2812_pin);
    gpio_set_dir(ws2812_pin, GPIO_OUT);
}

void set_pixel(int index, uint32_t color) {
    // Simula o envio do dado para os LEDs WS2812
    printf("LED %d: Cor %06X\n", index, color);
}
