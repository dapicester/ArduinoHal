/**
 * @file Button.h
 * @author Paolo D'Apice <paolo.dapice@gmail.com>
 */

#ifndef BUTTON_H
#define BUTTON_H

#include "Arduino.h"

// TODO pullup/pulldown

class Button {
public:
    Button(byte pin, long debounceDelay = 50L);

    boolean isPressed();
    boolean isChanged();

private:
    byte pin;
    boolean state;
    boolean prevState;
    long debounceDelay;
    long lastDebounceTime;
};

#endif /* BUTTON_H */

