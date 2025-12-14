#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "domain/control.h"
#include "hal/gpio.h"

void app_main(void)
{
    gpio_init();

    // demo: alterna valores "como si" viniesen de ADC
    while (1) {
        uint16_t adc_value = 2500;
        gpio_set_led(should_led_be_on(adc_value));
        vTaskDelay(pdMS_TO_TICKS(500));

        adc_value = 1000;
        gpio_set_led(should_led_be_on(adc_value));
        vTaskDelay(pdMS_TO_TICKS(500));
    }
}
