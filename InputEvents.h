#ifndef INPUTEVENTS_H
#define INPUTEVENTS_H

#include <optional>
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

struct MouseEvent
{
    std::optional<MouseButtons> button;
    std::optional<MouseButtonState> button_state;

    std::optional<std::pair<unsigned int, unsigned int>> pos;
};

struct KeyboardEvent
{
    std::string key;
};


#endif