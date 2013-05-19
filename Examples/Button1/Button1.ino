/**
 Blink led when button is pushed.
 */

#include <Button.h>
#include <Led.h>

Button button(7);
Led led(13);

void setup() {
}

void loop() {
  button.isPressed() ? led.on() : led.off();
}
