#ifndef __RTT_KEY_H__
#define __RTT_KEY_H__

#include <entry.h>

#define KEY_PIN          GET_PIN(A, 0)
#define KEY_VALUE        rt_pin_read(KEY_PIN)

void key_init(void);

#endif
