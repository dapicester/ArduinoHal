/**
 Fade pullup led on PWM pin.
 */

#include <Led.h>

Led led(11, PULLUP);

byte brightness = 255; // for pullup 255 means off
byte fadeAmount = -5;  // hence fadeAmount is negative
 
void setup() {
}

void loop() {
  led.setValue(brightness);
  brightness += fadeAmount;
  if (brightness == 0 || brightness == 255) {
    fadeAmount = -fadeAmount;
  }
  
  delay(30);
}
