#include "control.h"

#define THRESHOLD 2000

bool should_led_be_on(uint16_t adc_value)
{
    return adc_value >= THRESHOLD;
}
