#include "hal/gpio.h"
#include "app/control_task.h"

void app_main(void)
{
    gpio_init();
    control_task_start();
}