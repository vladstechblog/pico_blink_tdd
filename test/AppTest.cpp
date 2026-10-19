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

void gpio_put(uint pinNum, bool value){
  mock_c()->actualCall("gpio_put")
    ->withUnsignedIntParameters("pinNum", pinNum)
    ->withBoolParameters("value", value);
}

void sleep_ms(uint32_t delay_ms){
  mock_c()->actualCall("sleep_ms")
    ->withUnsignedIntParameters("delay_ms", delay_ms);
}

}

#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

TEST_GROUP(App){
  
  void record_pin_setup_expectations(){
    mock().expectOneCall("gpio_init")
      .withUnsignedIntParameter("pinNum", LED_PIN);

    mock().expectOneCall("gpio_set_dir")
      .withUnsignedIntParameter("pinNum", LED_PIN)
      .withBoolParameter("pinDir", GPIO_OUT);
  }

  void record_blink_expectations(){
    mock().expectOneCall("gpio_put")
      .withUnsignedIntParameter("pinNum", LED_PIN)
      .withBoolParameter("value", true);

    mock().expectOneCall("sleep_ms")
      .withUnsignedIntParameter("delay_ms", BLINK_DELAY);

    mock().expectOneCall("gpio_put")
      .withUnsignedIntParameter("pinNum", LED_PIN)
      .withBoolParameter("value", false);

    mock().expectOneCall("sleep_ms")
      .withUnsignedIntParameter("delay_ms", BLINK_DELAY);
  }

  void setup(){
    //TODO
  }

  void teardown(){
    mock().clear();;
  }
};


TEST(App, LedPinSetupTest){
  record_pin_setup_expectations();
  configure_led_gpio_pin(LED_PIN, GPIO_OUT);
  mock().checkExpectations();
}


TEST(App, Blink){
  record_blink_expectations();
  blink(LED_PIN, BLINK_DELAY);
  mock().checkExpectations();
}


TEST(App, AppMainConfiguresGPIOAndBlinks){
  record_pin_setup_expectations();
  record_blink_expectations();
  app_main();
  mock().checkExpectations();
}
