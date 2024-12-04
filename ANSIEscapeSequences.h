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

struct Mouse
{
    bool isEnabled;

    Mouse() = delete;
    Mouse(bool enable);
};

struct MouseSGR
{
    bool isEnabled;

    MouseSGR() = delete;
    MouseSGR(bool enable);
};

struct MouseURXVT
{
    bool isEnabled;

    MouseURXVT() = delete;
    MouseURXVT(bool enable);
};

struct AltBuffer
{
    bool isEnabled;

    AltBuffer() = delete;
    AltBuffer(bool enable);
};

struct Clear
{
    Clear();
};

struct ResetStyle
{
    ResetStyle();
};

std::ostream &operator<<(std::ostream &os, const Move &move);
std::ostream &operator<<(std::ostream &os, const Size &size);

std::ostream &operator<<(std::ostream &os, const ColorRGB &color);
std::ostream &operator<<(std::ostream &os, const BgColorRGB &color);

std::ostream &operator<<(std::ostream &os, const Mouse &mouse);
std::ostream &operator<<(std::ostream &os, const MouseSGR &mousesgr);
std::ostream &operator<<(std::ostream &os, const MouseURXVT &mouseurxvt);

std::ostream &operator<<(std::ostream &os, const AltBuffer &altbuffer);

std::ostream &operator<<(std::ostream &os, const Clear &clear);
std::ostream &operator<<(std::ostream &os, const ResetStyle &reset);

#endif