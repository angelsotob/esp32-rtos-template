#include "gpio.h"
#include "driver/gpio.h"

#define LED_GPIO GPIO_NUM_2   // típico LED integrado en muchos devkits (ajústalo luego)

void gpio_init(void)
{
    gpio_config_t io_conf = {
        .pin_bit_mask = 1ULL << LED_GPIO,
        .mode = GPIO_MODE_OUTPUT,
        .pull_up_en = GPIO_PULLUP_DISABLE,
        .pull_down_en = GPIO_PULLDOWN_DISABLE,
        .intr_type = GPIO_INTR_DISABLE,
    };
    gpio_config(&io_conf);
}

void gpio_set_led(bool on)
{
    gpio_set_level(LED_GPIO, on ? 1 : 0);
}
