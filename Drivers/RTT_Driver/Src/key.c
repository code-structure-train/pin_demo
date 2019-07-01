#include <key.h>

void key_init(void)
{
  rt_pin_mode(KEY_PIN, PIN_MODE_INPUT);
}
