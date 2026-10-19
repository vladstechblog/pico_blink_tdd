#ifndef D_App_H
#define D_App_H

#define LED_PIN 15
#define BLINK_DELAY 500

void app_main(void);
void configure_led_gpio_pin(uint, bool);
void blink(uint, uint32_t);

#endif  /* D_FakeApp_H */
