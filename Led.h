/**
 * @file Led.h
 * @author Paolo D'Apice <paolo.dapice@gmail.com>
 */

#ifndef LED_H
#define LED_H

#include "Arduino.h"

enum LedMode {
    PULLUP,
    PULLDOWN
};

class Led {
public:
    Led(byte pin, LedMode mode = PULLUP);
    ~Led() {}

    void on();
    void off();
    void toggle() { state ? off() : on(); }

    boolean isOn() const { return state; }
    boolean isOff() const { return !state; }

    // assume PWM for these

    void setValue(byte value);
    void incrValue(byte incr);
    void decrValue(byte incr);
    byte getValue() const { return value; }

private:
    byte pin;
    const LedMode mode;
    boolean state;
    byte value;
};

#endif /* LED_H */

