#ifndef TERMINALTWEAKS_H
#define TERMINALTWEAKS_H

#include <iostream>
#include "Color.h"

struct Move
{
    unsigned int m_x;
    unsigned int m_y;

    Move() = delete;
    Move(unsigned int x, unsigned int y);
};

struct Size
{
    unsigned int m_x;
    unsigned int m_y;

    Size() = delete;
    Size(unsigned int x, unsigned int y);
};

std::ostream &operator<<(std::ostream &os, const Move &move);
std::ostream &operator<<(std::ostream &os, const Size &size);

std::ostream &operator<<(std::ostream &os, const ColorRGB &color);
std::ostream &operator<<(std::ostream &os, const BgColorRGB &color);

#endif