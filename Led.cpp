/**
 * @file Led.cpp
 * @author Paolo D'Apice <paolo.dapice@gmail.com>
 */

#include "Led.h"

Led::Led(byte p, LedMode m) :
    pin(p), mode(m), state(false), value(0) {
    pinMode(pin, OUTPUT);
}

void Led::on() {
    digitalWrite(pin, mode == PULLUP ? HIGH : LOW);
    state = true;
}

void Led::off() {
    digitalWrite(pin, mode == PULLUP ? LOW : HIGH);
    state = false;
}

void Led::setValue(byte value) {
    analogWrite(pin, value);
    this->value = value;
    state = mode == PULLUP ? value > 127 : value < 128;
}

void Led::incrValue(byte incr) {
    setValue((value + incr >= 255) ? 255 : value + incr);
}

void Led::decrValue(byte incr) {
    setValue((value - incr <= 0) ? 0 : value - incr);
}

