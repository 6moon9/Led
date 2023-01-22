#include <Arduino.h>

#include "Led.h"

LedRGB::LedRGB(uint8_t rPin, uint8_t gPin, uint8_t bPin, bool iCommon = false)
{
    pins[0] = rPin;
    pins[1] = gPin;
    pins[2] = bPin;
    common = iCommon;
    pinMode(pins[0], OUTPUT);
    pinMode(pins[1], OUTPUT);
    pinMode(pins[2], OUTPUT);
    off();
}

/**
 * Turn on the led
 */
void LedRGB::on(int iR = r, int iG = g, int iB = b)
{
    state = true;
    r = iR;
    g = iG;
    b = iB;
    analogWrite(pins[0], state ? r : 0);
    analogWrite(pins[1], state ? g : 0);
    analogWrite(pins[1], state ? b : 0);
}

/**
 * Turn off the led
 */
void LedRGB::off()
{
    state = false;
    analogWrite(pins[0], state ? 255 : 0);
    analogWrite(pins[1], state ? 255 : 0);
    analogWrite(pins[1], state ? 255 : 0);
}

/**
 * Toggle the led state
 */
void LedRGB::toggle()
{
    state = !state;
    analogWrite(pins[0], state ? r : 0);
    analogWrite(pins[1], state ? g : 0);
    analogWrite(pins[1], state ? b : 0);
}

/**
 * Make the led blinking
 * @param delay: the delay to wait between each tipping of the led
 * @param times: the number of times the led toggle
 */
void LedRGB::blink(int delayTime, int times)
{
    for (int i = 0; i < times; i++)
    {
        toggle();
        delay(delayTime);
    }
}
