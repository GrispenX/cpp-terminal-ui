#include "Button.h"

Button::Button()
{
    m_text = "Button";
}

void Button::SetText(std::string text)
{
    m_text = text;
}

void Button::SetTextColor(ColorRGB color)
{
    m_textColor = color;
}

void Button::SetBgColor(BgColorRGB color)
{
    m_bgColor = color;
}

void Button::AddEvent(MouseButtons button, MouseButtonState state, std::function<void()> on_event)
{
    MouseButtonEvent event;
    event.button = button;
    event.state = state;
    m_onButtonEvents.push_back(std::make_pair(event, on_event));
}

void Button::HandleEvent(std::variant<MouseMoveEvent, MouseButtonEvent, KeyboardEvent> event)
{
    if(std::holds_alternative<MouseButtonEvent>(event))
    {
        auto pos = GetPos();
        auto size = GetSize();
        MouseButtonEvent e = std::get<MouseButtonEvent>(event);
        if(e.pos.first >= pos.first && e.pos.first <= pos.first + size.first - 1 &&
        e.pos.second >= pos.second && e.pos.second <= pos.second + size.second - 1)
        {
            for(auto on_event : m_onButtonEvents)
            {
                if(on_event.first.button == e.button && on_event.first.state == e.state)
                {
                    on_event.second();
                }
            }
        }
    }
}

void Button::Render()
{
    std::cout << m_textColor << m_bgColor;
    for(int y = GetPos().second; y < GetPos().second + GetSize().second; y++)
    {
        std::cout << Move(GetPos().first, y);
        for(int x = 0; x < GetSize().first; x++)
        {
            std::cout << " ";
        }
    }

    if(m_text.length() > GetSize().first)
    {
        m_text = m_text.substr(0, GetSize().first);
    }

    unsigned int text_x = (GetSize().first - m_text.length()) / 2 + GetPos().first;
    unsigned int text_y = (GetSize().second - 1) / 2 + GetPos().second;

    std::cout << Move(text_x, text_y) << m_text;
}