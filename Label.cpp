#include "Label.h"

Label::Label()
{

}

Label::Label(std::string text)
{
    m_text = text;
}

void Label::SetText(std::string text)
{
    m_text = text;
}

void Label::SetTextColor(ColorRGB color)
{
    m_textColor = color;
}

void Label::SetBgColor(BgColorRGB color)
{
    m_bgColor = color;
}

void Label::Render()
{
    std::cout << m_textColor << m_bgColor;
    for(int x = GetPos().first; x < GetPos().first + GetSize().first; x++)
    {
        for(int y = GetPos().second; y < GetPos().second + GetSize().second; y++)
        {
            std::cout << Move(x, y) << " ";
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