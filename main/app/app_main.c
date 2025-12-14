#include "gpio.h"
#include "control_task.h"

void app_main(void)
{
    gpio_init();
    control_task_start();
}