#include <led.h>

void led_init(void)
{
  rt_pin_mode(LED_G_PIN, PIN_MODE_OUTPUT);
  rt_pin_mode(LED_G_PIN, PIN_MODE_OUTPUT);
  rt_pin_mode(LED_G_PIN, PIN_MODE_OUTPUT);
  rt_pin_mode(LED_G_PIN, PIN_MODE_OUTPUT);
}
