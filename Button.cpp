#include "Button.h"

Button::Button()
{
    m_text = "Button";
}

Button::Button(std::string text, std::function<void()> on_click)
{
    m_text = text;
    m_onClick = on_click;
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

void Button::OnClick(std::function<void()> on_click)
{
    m_onClick = on_click;
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