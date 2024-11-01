#include "Color.h"
#include <iostream>

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

std::ostream &operator<<(std::ostream &os, const ColorRGB &color)
{
    os << "\033[38;2;" << int(color.r) << ";" << int(color.g) << ";" << int(color.b) << "m";
    return os;
}

std::ostream &operator<<(std::ostream &os, const BgColorRGB &color)
{
    os << "\033[48;2;" << int(color.r) << ";" << int(color.g) << ";" << int(color.b) << "m";
    return os;
}