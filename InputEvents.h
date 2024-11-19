#ifndef INPUTEVENTS_H
#define INPUTEVENTS_H

#include <utility>
#include <string>

enum MouseButtons
{
    LEFT,
    RIGHT,
    MIDDLE
};

enum MouseButtonState
{
    PRESSED,
    RELEASED
};

struct MouseMoveEvent
{
    std::pair<unsigned int, unsigned int> pos;
};

struct MouseButtonEvent
{
    MouseButtons button;
    MouseButtonState state;
};

struct KeyboardEvent
{
    std::string key;
};


#endif