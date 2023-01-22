#include <Arduino.h>

class Led
{
    public:
        Led(uint8_t iPin, bool iReversed = false);
        void on();
        void off();
        void toggle();
        void blink(int delayTime, int times);
        byte state;
        uint8_t pin;
        bool reversed = false;
};

class LedRGB
{
    public:
        LedRGB(uint8_t rPin, uint8_t gPin, uint8_t bPin, bool iCommon = false);
        void on(int iR = r, int iG = g, int iB = b);
        void off();
        void toggle();
        void blink(int delayTime, int times);
        bool state;
        uint8_t pins[3];
        int r = 255;
        int g = 255;
        int b = 255;
        bool common = false;
};