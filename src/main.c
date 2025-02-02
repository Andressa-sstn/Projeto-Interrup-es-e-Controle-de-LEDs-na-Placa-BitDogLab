#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/irq.h"
#include "ws2812.h"  // Biblioteca para LEDs WS2812

// Definições de pinos
#define BUTTON_A 5
#define BUTTON_B 6
#define LED_RED 11
#define LED_GREEN 12
#define LED_BLUE 13
#define WS2812_PIN 7

// Variáveis globais
volatile int number = 0;
volatile bool buttonA_pressed = false;
volatile bool buttonB_pressed = false;

// Função para debounce do botão
bool debounce(uint pin) {
    static uint32_t last_time = 0;
    uint32_t now = time_us_32();
    if (now - last_time > 200000) {  // 200ms para evitar bouncing
        last_time = now;
        return true;
    }
    return false;
}

// Funções de interrupção para os botões
void buttonA_callback(uint gpio, uint32_t events) {
    if (debounce(BUTTON_A)) {
        buttonA_pressed = true;
    }
}

void buttonB_callback(uint gpio, uint32_t events) {
    if (debounce(BUTTON_B)) {
        buttonB_pressed = true;
    }
}

// Função para piscar o LED vermelho
void blink_led_red() {
    gpio_put(LED_RED, 1);
    sleep_ms(100);
    gpio_put(LED_RED, 0);
    sleep_ms(100);
}

// Função para exibir números na matriz WS2812
void show_number(int num) {
    uint32_t colors[] = {0xFF0000, 0x00FF00, 0x0000FF, 0xFFFF00, 0xFF00FF,
                         0x00FFFF, 0xFFFFFF, 0x888888, 0x444444, 0x222222};

    for (int i = 0; i < 25; i++) {
        set_pixel(i, colors[num]);  // Atualiza a matriz com a cor correspondente ao número
    }
}

int main() {
    stdio_init_all();

    // Configuração dos GPIOs
    gpio_init(LED_RED);
    gpio_set_dir(LED_RED, GPIO_OUT);
    gpio_init(BUTTON_A);
    gpio_set_dir(BUTTON_A, GPIO_IN);
    gpio_pull_up(BUTTON_A);
    gpio_init(BUTTON_B);
    gpio_set_dir(BUTTON_B, GPIO_IN);
    gpio_pull_up(BUTTON_B);

    // Configuração das interrupções
    gpio_set_irq_enabled_with_callback(BUTTON_A, GPIO_IRQ_EDGE_FALL, true, &buttonA_callback);
    gpio_set_irq_enabled_with_callback(BUTTON_B, GPIO_IRQ_EDGE_FALL, true, &buttonB_callback);

    // Inicializa WS2812
    init_ws2812(WS2812_PIN);

    while (1) {
        blink_led_red();

        if (buttonA_pressed) {
            number = (number + 1) % 10;
            show_number(number);
            buttonA_pressed = false;
        }

        if (buttonB_pressed) {
            number = (number - 1 + 10) % 10;
            show_number(number);
            buttonB_pressed = false;
        }
    }

    return 0;
}
