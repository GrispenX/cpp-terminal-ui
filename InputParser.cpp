#include "InputParser.h"
#include "MouseTranslations.h"

InputParser::InputParser()
{
    m_state = State::IDLE;
}


void InputParser::Reset()
{
    m_state = State::IDLE;
    m_buf.clear();
    m_action.clear();
    m_x = 0;
    m_y = 0;
}

// std::optional<std::variant<MouseMoveEvent, MouseButtonEvent, KeyboardEvent>> InputParser::CreateEvent()
// {
//     if(m_action == LMB)
//     {
//         return MouseButtonEvent{LEFT, m_buttonState, std::make_pair(m_x, m_y)};
//     }
// }

std::optional<std::variant<MouseMoveEvent, MouseButtonEvent, KeyboardEvent>> InputParser::ParseChar(char c)
{
    switch(m_state)
    {
    case State::IDLE:
        if(c == '\033')
        {
            m_state = State::SQUARE_BR;
        } else {
            return KeyboardEvent{c};
        }
        break;

    case State::SQUARE_BR:
        if(c == '[')
        {
            m_state = State::TRIANGLE_BR;
        } else {
            Reset();
        }
        break;

    case State::TRIANGLE_BR:
        if(c == '<')
        {
            m_state = State::ACTION;
        } else {
            Reset();
        }
        break;

    case State::ACTION:
        if(isdigit(c))
        {
            m_buf += c;
        } else if(c == ';' && !m_buf.empty()) {
            m_action = m_buf;
            m_buf.clear();
            m_state = State::X;
        } else {
            Reset();
        }
        break;

    case State::X:
        if(isdigit(c))
        {
            m_buf += c;
        } else if(c == ';' && !m_buf.empty()) {
            m_x = std::stoi(m_buf);
            m_buf.clear();
            m_state = State::Y;
        } else {
            Reset();
        }
        break;

    case State::Y:
        if(isdigit(c))
        {
            m_buf += c;
        } else if((c == 'm' || c == 'M') && !m_buf.empty()) {
            m_y = std::stoi(m_buf);
            m_buf.clear();
            m_buttonState = c == 'M' ? PRESSED : RELEASED;

            std::optional<std::variant<MouseMoveEvent, MouseButtonEvent, KeyboardEvent>> event;
            if(m_action == MOVE)
            {
                event = MouseMoveEvent{std::make_pair(m_x, m_y)};
            } else if(m_action == LMB) {
                event = MouseButtonEvent{LEFT, m_buttonState, std::make_pair(m_x, m_y)}; 
            } else if(m_action == RMB) {
                event = MouseButtonEvent{RIGHT, m_buttonState, std::make_pair(m_x, m_y)};
            } else if(m_action == MMB) {
                event = MouseButtonEvent{MIDDLE, m_buttonState, std::make_pair(m_x, m_y)};
            } else event = std::nullopt;
            Reset();
            return event;
        } else {
            Reset();
        }
        break;
    }
    return std::nullopt;
}