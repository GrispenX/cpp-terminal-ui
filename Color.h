#ifndef COLOR_H
#define COLOR_H

#include <cstdint>
#include <iostream>

class ColorRGB
{
public:
    ColorRGB();
    ColorRGB(uint8_t red, uint8_t green, uint8_t blue);
    
    uint8_t r;
    uint8_t g;
    uint8_t b;
};

class BgColorRGB : public ColorRGB
{
public:
    BgColorRGB();
    BgColorRGB(uint8_t red, uint8_t green, uint8_t blue);
};

#endif