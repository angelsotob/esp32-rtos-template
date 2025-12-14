#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "domain/control.h"
#include "hal/gpio.h"

static void control_task(void *arg)
{
    (void)arg;

    while (1) {
        // Demo provisional: valores "como si" viniesen de ADC
        uint16_t adc_value = 2500;
        gpio_set_led(should_led_be_on(adc_value));
        vTaskDelay(pdMS_TO_TICKS(500));

        adc_value = 1000;
        gpio_set_led(should_led_be_on(adc_value));
        vTaskDelay(pdMS_TO_TICKS(500));
    }
}

void control_task_start(void)
{
    // stack/priority: valores razonables para arrancar (los afinamos luego)
    xTaskCreate(control_task, "control", 2048, NULL, 5, NULL);
}
