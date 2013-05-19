/**
 Toggle led when button is pushed.
 */

#include <Button.h>
#include <Led.h>

Button button(7);
Led led(13);

void setup() {
  led.on();
}

void loop() {
  if (button.isChanged())
    led.toggle();
}
