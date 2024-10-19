#ifndef COLOR_H
#define COLOR_H

#include <cstdint>

class ColorRGB
{
private:
    
public:
    ColorRGB();
    ColorRGB(uint8_t red, uint8_t green, uint8_t blue);
    
    uint8_t r;
    uint8_t g;
    uint8_t b;
};

#endif