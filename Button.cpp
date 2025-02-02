#include "Button.h"

Button::Button()
{
    m_text = "Button";
}

Button::Button(std::string text)
{
    m_text = text;
    m_pressedBackgroundRGB = BackgroundRGB(150, 150, 150);
    m_pressedForegroundRGB = ForegroundRGB(0, 0, 0);
    SetBackground(BackgroundRGB(255, 255, 255));
    SetForeground(ForegroundRGB(0, 0, 0));
}

void Button::SetText(std::string text)
{
    m_text = text;
}

void Button::SetPressedBackground(BackgroundRGB color)
{
    m_pressedBackgroundRGB = color;
}

void Button::SetPressedForeground(ForegroundRGB color)
{
    m_pressedForegroundRGB = color;
}

BackgroundRGB Button::GetPressedBackground()
{
    return m_pressedBackgroundRGB;
}

ForegroundRGB Button::GetPressedForeground()
{
    return m_pressedForegroundRGB;
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
            SetActive(e.state == PRESSED);
            for(auto on_event : m_onButtonEvents)
            {
                if(on_event.first.button == e.button && on_event.first.state == e.state)
                {
                    on_event.second();
                }
            }
        }
        else SetActive(false);
    }
}

void Button::Render()
{
    auto pos = GetPos();
    auto size = GetSize();

    std::cout << (IsActive() ? GetPressedBackground() : GetBackground());
    std::cout << (IsActive() ? GetPressedForeground() : GetForeground());
    for(int y = pos.second; y < pos.second + size.second; y++)
    {
        std::cout << Move(pos.first, y);
        for(int x = pos.first; x < pos.first + size.first; x++)
        {
            std::cout << " ";
        }
    }

    if(m_text.size() > size.first)
    {
        std::cout << Move(pos.first, (size.second - 1) / 2 + pos.second) << m_text.substr(0, size.first - 1) << "…";
    } else {
        std::cout << Move((size.first - m_text.size()) / 2 + pos.first, (size.second - 1) / 2 + pos.second) << m_text;
    }

    std::cout << ResetStyle();
}

Button &Button::operator|(const BackgroundRGB &color)
{
    SetBackground(color);
    return *this;
}

Button &Button::operator|(const ForegroundRGB &color)
{
    SetForeground(color);
    return *this;
}
