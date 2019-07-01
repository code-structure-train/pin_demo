#ifndef __RTT_LED_H__
#define __RTT_LED_H__

#include <entry.h>

#define LED_G_PIN    GET_PIN(D, 12)
#define LED_O_PIN    GET_PIN(D, 13)
#define LED_R_PIN    GET_PIN(D, 14)
#define LED_B_PIN    GET_PIN(D, 15)

void led_init(void);

#endif
