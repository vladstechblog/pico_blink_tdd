#include <stdbool.h>
#define GPIO_OUT true

typedef unsigned int uint;
void gpio_init(uint);
void gpio_set_dir(uint, bool);
void gpio_put(uint, bool);
