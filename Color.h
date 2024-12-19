#ifndef COLOR_H
#define COLOR_H

#include <cstdint>
#include <iostream>

class ForegroundRGB
{
public:
    ForegroundRGB();
    ForegroundRGB(uint8_t red, uint8_t green, uint8_t blue);
    
    uint8_t r;
    uint8_t g;
    uint8_t b;
};

class BackgroundRGB : public ForegroundRGB
{
public:
    BackgroundRGB();
    BackgroundRGB(uint8_t red, uint8_t green, uint8_t blue);
};

#endif