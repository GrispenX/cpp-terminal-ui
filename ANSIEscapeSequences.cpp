#include "ANSIEscapeSequences.h"

Move::Move(unsigned int x, unsigned int y)
{
    m_x = x;
    m_y = y;
}

Size::Size(unsigned int x, unsigned int y)
{
    m_x = x;
    m_y = y;
}

Mouse::Mouse(bool enable)
{
    isEnabled = enable;
}

MouseSGR::MouseSGR(bool enable)
{
    isEnabled = enable;
}

MouseURXVT::MouseURXVT(bool enable)
{
    isEnabled = enable;
}

AltBuffer::AltBuffer(bool enable)
{
    isEnabled = enable;
}

Clear::Clear() {};

ResetStyle::ResetStyle() {};

std::ostream &operator<<(std::ostream &os, const Move &move)
{
    os << "\033[" << move.m_y << ";" << move.m_x << "f";
    return os;
}

std::ostream &operator<<(std::ostream &os, const Size &size)
{
    os << "\033[8;" << size.m_y << ";" << size.m_x << "t";
    return os;
}

std::ostream &operator<<(std::ostream &os, const ForegroundRGB &color)
{
    os << "\033[38;2;" << int(color.r) << ";" << int(color.g) << ";" << int(color.b) << "m";
    return os;
}

std::ostream &operator<<(std::ostream &os, const BackgroundRGB &color)
{
    os << "\033[48;2;" << int(color.r) << ";" << int(color.g) << ";" << int(color.b) << "m";
    return os;
}

std::ostream &operator<<(std::ostream &os, const Mouse &mouse)
{
    if(mouse.isEnabled) {
        os << "\033[?1003h";
    } else {
        os << "\033[?1003l";
    }
    return os;
}

std::ostream &operator<<(std::ostream &os, const MouseSGR &mousesgr)
{
    if(mousesgr.isEnabled) {
        os << "\033[?1006h";
    } else {
        os << "\033[?1006l";
    }
    return os;
}

std::ostream &operator<<(std::ostream &os, const MouseURXVT &mouseurxvt)
{
    if(mouseurxvt.isEnabled) {
        os << "\033[?1015h";
    } else {
        os << "\033[?1015l";
    }
    return os;
}

std::ostream &operator<<(std::ostream &os, const AltBuffer &altbuffer)
{
    if(altbuffer.isEnabled) {
        os << "\033[?1049h";
    } else {
        os << "\033[?1049l";
    }
    return os;
}

std::ostream &operator<<(std::ostream &os, const Clear &clear)
{
    std::cout << "\033[2J";
    return os;
}

std::ostream &operator<<(std::ostream &os, const ResetStyle &reset)
{
    std::cout << "\033[0m";
    return os;
}