/**
 * @file Button.cpp
 * @author Paolo D'Apice <paolo.dapice@gmail.com>
 */

#include "Button.h"

Button::Button(byte p, long delay) :
        pin(p), state(LOW), prevState(LOW),
        debounceDelay(delay), lastDebounceTime(0L) {
    pinMode(pin, INPUT);
}

boolean Button::isPressed() {
    return digitalRead(pin);
}

boolean Button::isChanged() {
    boolean ret = false;
    boolean reading = digitalRead(pin);
    if (reading != prevState) {
        // switch changed
        lastDebounceTime = millis();
    }

    if ((millis() - lastDebounceTime) > debounceDelay) {
        // reading holds for longer than debounce delay, so take it

        if (reading != state) {
            // button state changed
            state = reading;
            ret = (state == HIGH);
        }
    }

    prevState = reading;
    return ret;
}

