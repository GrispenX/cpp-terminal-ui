#ifndef INPUTPARSER_H
#define INPUTPARSER_H

#include <optional>
#include <variant>
#include "InputEvents.h"

class InputParser
{
private:
    enum class State
    {
        IDLE,
        SQUARE_BR,
        TRIANGLE_BR,
        ACTION,
        X,
        Y
    };

    std::string m_buf;
    std::string m_action;
    unsigned int m_x, m_y;
    MouseButtonState m_buttonState;
    State m_state;

    void Reset();
    // std::optional<std::variant<MouseMoveEvent, MouseButtonEvent, KeyboardEvent>> CreateEvent();

public:
    InputParser();
    std::optional<std::variant<MouseMoveEvent, MouseButtonEvent, KeyboardEvent>> ParseChar();
};

#endif