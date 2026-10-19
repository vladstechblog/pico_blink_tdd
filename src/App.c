#include "hardware/gpio.h"
#include "pico/time.h"
#include "App.h"

void configure_led_gpio_pin(uint pinNumber, bool pinDirection){
  gpio_init(pinNumber); 
  gpio_set_dir(pinNumber, pinDirection); 
}

void blink(uint ledPin, uint32_t delay){
  gpio_put(ledPin, true);
  sleep_ms(delay);
  gpio_put(ledPin, false);
  sleep_ms(delay);
}

void app_main(void){
  configure_led_gpio_pin(LED_PIN, GPIO_OUT);
  blink(LED_PIN, BLINK_DELAY);
}
