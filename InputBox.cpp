#include "InputBox.h"

InputBox::InputBox()
{
    
}

InputBox::InputBox(std::string hint)
{
    m_hint = hint;
}

void InputBox::SetHint(std::string hint)
{
    m_hint = hint;
}

std::string InputBox::GetInput()
{
    return m_input;
}

void InputBox::HandleEvent(std::variant<MouseMoveEvent, MouseButtonEvent, KeyboardEvent> event)
{
    if(std::holds_alternative<KeyboardEvent>(event))
    {
        KeyboardEvent e = std::get<KeyboardEvent>(event);
        if(e.key == '\177' && !m_input.empty())
        {
            m_input.pop_back();
        } else {
            m_input.push_back(e.key);
        }
    }
}

void InputBox::Render()
{
    auto pos = GetPos();
    auto size = GetSize();

    std::cout << GetBackground() << GetForeground();
    for(int y = pos.second; y < pos.second + size.second; y++)
    {
        std::cout << Move(pos.first, y);
        for(int x = pos.first; x < pos.first + size.first; x++)
        {
            std::cout << " ";
        }
    }

    if(m_input.size() > 0)
    {
        if(m_input.size() > size.first)
        {
            std::cout << Move(pos.first, (size.second - 1) / 2 + pos.second) << "…" << m_input.substr(m_input.size() - size.first, size.first);
        } else {
            std::cout << Move(pos.first, (size.second - 1) / 2 + pos.second) << m_input;
        }
    } else {
        if(m_hint.size() > size.first)
        {
            std::cout << Move(pos.first, (size.second - 1) / 2 + pos.second) << m_hint.substr(0, size.first - 1) << "…"; 
        } else {
            std::cout << Move(pos.first, (size.second - 1) / 2 + pos.second) << m_hint;
        }
    }

    std::cout << ResetStyle();
}

InputBox &InputBox::operator|(const BackgroundRGB &color)
{
    SetBackground(color);
    return *this;
}

InputBox &InputBox::operator|(const ForegroundRGB &color)
{
    SetForeground(color);
    return *this;
}