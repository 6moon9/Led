#include <Arduino.h>

class Led
{
    public:
        Led(uint8_t iPin, bool iReversed = false);
        void on();
        void off();
        void toggle();
        void blink(int delayTime);
        byte state;
        uint8_t pin;
        bool reversed = false;
};
