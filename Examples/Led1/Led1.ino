/**
 Blink led on pin 13.
 */

#include <Led.h>

Led led(13);

void setup() {
  led.on();
}

void loop() {
  delay(1000);
  led.toggle();
}
