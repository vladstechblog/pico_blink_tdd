#include "hardware/gpio.h"
#include "App.h"

void app_main(void){
  gpio_init(LED_PIN); 
  gpio_set_dir(LED_PIN, GPIO_OUT); 
}
