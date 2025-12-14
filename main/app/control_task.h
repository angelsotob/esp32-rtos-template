#pragma once

#include <stdint.h>

#define ADC_HIGH 2500
#define ADC_LOW  1000
#define PERIOD_MS 500

#define CONTROL_TASK_STACK 2048
#define CONTROL_TASK_PRIO 5

void control_task_start(void);
