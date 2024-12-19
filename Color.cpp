#include "Color.h"
#include <iostream>

ForegroundRGB::ForegroundRGB()
{
    r = 255;
    g = 255;
    b = 255;
}

ForegroundRGB::ForegroundRGB(uint8_t red, uint8_t green, uint8_t blue)
{
    r = red;
    g = green;
    b = blue;
}

BackgroundRGB::BackgroundRGB()
{
    r = 0;
    g = 0;
    b = 0;
}

BackgroundRGB::BackgroundRGB(uint8_t red, uint8_t green, uint8_t blue)
{
    r = red;
    g = green;
    b = blue;
}
