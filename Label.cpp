#include "Label.h"

Label::Label(std::string text, unsigned int size_x, unsigned int size_y)
{
    m_text = text;
    m_sizeX = size_x;
    m_sizeY = size_y;
}

Label::Label(std::string text, unsigned int size_x, unsigned int size_y, ColorRGB text_color, ColorRGB bg_color)
{
    m_text = text;
    m_sizeX = size_x;
    m_sizeY = size_y;
    m_textColor = text_color;
    m_bgColor = bg_color;
}

void Label::Resize(unsigned int x, unsigned int y)
{
    m_sizeX = x;
    m_sizeY = y;
}

void Label::SetPos(unsigned int x, unsigned int y)
{
    m_posX = x;
    m_posY = y;
}

void Label::SetText(std::string text)
{
    m_text = text;
}

void Label::SetTextColor(ColorRGB color)
{
    m_textColor = color;
}

void Label::SetBgColor(ColorRGB color)
{
    m_bgColor = color;
}

std::string Label::GetText()
{
    return m_text;
}

ColorRGB Label::GetTextColor()
{
    return m_textColor;
}

ColorRGB Label::GetBgColor()
{
    return m_bgColor;
}

void Label::Render()
{

}