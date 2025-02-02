#include "InputBox.h"

InputBox::InputBox(std::string hint)
{
    m_hint = hint;
    m_hintForeground = ForegroundRGB(100, 100, 100);
    m_activeBackgroundRGB = BackgroundRGB(255, 255, 255);
    m_activeForegroundRGB = ForegroundRGB(0, 0, 0);
    SetBackground(BackgroundRGB(50, 50, 50)); 
    SetForeground(ForegroundRGB(255, 255, 255));
    s_validator = ".*";
}

InputBox::InputBox(std::string hint, std::regex validator)
{
    m_hint = hint;
    m_hintForeground = ForegroundRGB(100, 100, 100);
    m_activeBackgroundRGB = BackgroundRGB(255, 255, 255);
    m_activeForegroundRGB = ForegroundRGB(0, 0, 0);
    SetBackground(BackgroundRGB(50, 50, 50)); 
    SetForeground(ForegroundRGB(255, 255, 255));
    s_validator = validator;
}

void InputBox::SetHint(std::string hint)
{
    m_hint = hint;
}

void InputBox::SetActiveBackground(BackgroundRGB color)
{
    m_activeBackgroundRGB = color;
}

void InputBox::SetActiveForeground(ForegroundRGB color)
{
    m_activeForegroundRGB = color;
}

void InputBox::SetHintForeground(ForegroundRGB color)
{
    m_hintForeground = color;
}

BackgroundRGB InputBox::GetActiveBackground()
{
    return m_activeBackgroundRGB;
}

ForegroundRGB InputBox::GetActiveForeground()
{
    return m_activeForegroundRGB;
}

ForegroundRGB InputBox::GetHintForeground()
{
    return m_hintForeground;
}

std::string InputBox::GetInput()
{
    return m_input;
}

void InputBox::HandleEvent(std::variant<MouseMoveEvent, MouseButtonEvent, KeyboardEvent> event)
{
    if(std::holds_alternative<MouseButtonEvent>(event))
    {
        auto pos = GetPos();
        auto size = GetSize();
        MouseButtonEvent e = std::get<MouseButtonEvent>(event);
        if(e.pos.first >= pos.first && e.pos.first <= pos.first + size.first - 1 &&
           e.pos.second >= pos.second && e.pos.second <= pos.second + size.second - 1)
        {
            if(e.state == PRESSED)
            {
                SetActive(true);
            }
        }
        else
        {
            SetActive(false);
        }
    }
    else if(std::holds_alternative<KeyboardEvent>(event))
    {
        KeyboardEvent e = std::get<KeyboardEvent>(event);
        if(e.key == '\177' && !m_input.empty())
        {
            m_input.pop_back();
        }
        else
        {
            std::string inputWithCharacter = m_input + e.key;
            std::cmatch matches;

            std::regex_match(inputWithCharacter.c_str(), matches, s_validator);
            if(matches.length() > 0)
            {
                m_input.push_back(e.key);
            }

        }
    }
}

void InputBox::Render()
{
    auto pos = GetPos();
    auto size = GetSize();

    std::cout << (IsActive() ? GetActiveBackground() : GetBackground());
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
        std::cout << (IsActive() ? GetActiveForeground() : GetForeground());
        if(m_input.size() > size.first)
        {
            std::cout << Move(pos.first, (size.second - 1) / 2 + pos.second) << "…" << m_input.substr(m_input.size() - size.first, size.first);
        } else {
            std::cout << Move(pos.first, (size.second - 1) / 2 + pos.second) << m_input;
        }
    } else {
        std::cout << (IsActive() ? GetHintForeground() : GetForeground());
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