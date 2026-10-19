extern "C"
{
#include "App.h"
#include "CppUTestExt/MockSupport_c.h"
#include "hardware/gpio.h"

void gpio_init(uint pinNum){
  mock_c()->actualCall("gpio_init")
    ->withUnsignedIntParameters("pinNum", pinNum);
}

void gpio_set_dir(uint pinNum, bool pinDir){
  mock_c()->actualCall("gpio_set_dir")
    ->withUnsignedIntParameters("pinNum", pinNum)
    ->withBoolParameters("pinDir", pinDir);
}

}

#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

TEST_GROUP(App)
{
    void setup(){
      //TODO
    }

    void teardown(){
      mock().checkExpectations();
      mock().clear();;
    }
};

TEST(App, LedPinSetupTest){
  mock().expectOneCall("gpio_init")
    .withUnsignedIntParameter("pinNum", LED_PIN);

  mock().expectOneCall("gpio_set_dir")
    .withUnsignedIntParameter("pinNum", LED_PIN)
    .withBoolParameter("pinDir", GPIO_OUT);

  configure_led_gpio_pin(LED_PIN, GPIO_OUT);
}

