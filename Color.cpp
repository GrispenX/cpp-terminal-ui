#include "Color.h"

ColorRGB::ColorRGB()
{
    r = 255;
    g = 255;
    b = 255;
}

ColorRGB::ColorRGB(uint8_t red, uint8_t green, uint8_t blue)
{
    r = red;
    g = green;
    b = blue;
}

BgColorRGB::BgColorRGB()
{
    r = 0;
    g = 0;
    b = 0;
}

BgColorRGB::BgColorRGB(uint8_t red, uint8_t green, uint8_t blue)
{
    r = red;
    g = green;
    b = blue;
}
