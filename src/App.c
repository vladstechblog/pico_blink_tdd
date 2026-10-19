#include "hardware/gpio.h"
#include "pico/time.h"
#include "App.h"

void configure_led_gpio_pin(uint pinNumber, bool pinDirection){
  gpio_init(pinNumber); 
  gpio_set_dir(pinNumber, pinDirection); 
}

void blink(){
  gpio_put(LED_PIN, true);
  sleep_ms(500);
}

void app_main(void){
  configure_led_gpio_pin(LED_PIN, GPIO_OUT);
  blink();
}
