#include "ANSIEscapeSequences.h"

Move::Move(unsigned int x, unsigned int y)
{
    m_x = x;
    m_y = y;
}

std::ostream &operator<<(std::ostream &os, const Move &move)
{
    os << "\033[" << move.m_y << ";" << move.m_x << "f";
    return os;
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