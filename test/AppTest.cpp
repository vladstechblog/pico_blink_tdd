extern "C"
{
#include "App.h"
#include "CppUTestExt/MockSupport_c.h"
#include "hardware/gpio.h"

void gpio_init(uint pinNum){
  mock_c()->actualCall("gpio_init")
    ->withUnsignedIntParameters("pinNum", pinNum);
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

TEST(App, CallsGPIOInitWithCorrectArguments){
  unsigned int led_pin = 15;

  mock().expectOneCall("gpio_init")
    .withUnsignedIntParameter("pinNum", led_pin);

  app_main();
}

