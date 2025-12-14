#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "domain/control.h"
#include "hal/gpio.h"

#include "esp_log.h"
#include "control_task.h"

static const char *TAG = "control";

static void control_task(void *arg)
{
    (void)arg;

    while (1) {
        // Demo provisional: valores "como si" viniesen de ADC
        // TODO: replace adc_value demo with queue-received ADC sample
        uint16_t adc_value = ADC_HIGH;
        gpio_set_led(should_led_be_on(adc_value));
        vTaskDelay(pdMS_TO_TICKS(PERIOD_MS));

        adc_value = ADC_LOW;
        gpio_set_led(should_led_be_on(adc_value));
        vTaskDelay(pdMS_TO_TICKS(PERIOD_MS));
    }
}

void control_task_start(void)
{
    BaseType_t ok = xTaskCreate(control_task, "control", CONTROL_TASK_STACK, NULL, CONTROL_TASK_PRIO, NULL);
    if (ok != pdPASS) {
        ESP_LOGE(TAG, "Failed to create control task");
    } else {
        ESP_LOGI(TAG, "Control task started");
    }
}
