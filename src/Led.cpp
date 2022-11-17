#include <Arduino.h>

#include "Led.h"

Led::Led(uint8_t iPin, bool iReversed = false)
{
    pin = iPin;
    reversed = iReversed;
    pinMode(pin, INPUT);
    off();
}

/**
 * Turn on the led
 */
void Led::on()
{
    state = HIGH;
    digitalWrite(pin, reversed ? !state : state);
}

/**
 * Turn off the led
 */
void Led::off()
{
    state = LOW;
    digitalWrite(pin, reversed ? !state : state);
}

/**
 * Toggle the led state
 */
void Led::toggle()
{
    state = !state;
    digitalWrite(pin, reversed ? !state : state);
}

/**
 * Make the led blinking
 * @param delay: the delay to wait between each tipping of the led
 */
void Led::blink(int delayTime)
{
    toggle();
    delay(delayTime);
}
