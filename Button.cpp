#include "Button.h"

Button::Button(std::string text, std::function<void()> on_click, unsigned int size_x, unsigned int size_y)
{
    m_text = text;
    m_onClick = on_click;
    m_sizeX = size_x;
    m_sizeY = size_y;
}

Button::Button(std::string text, std::function<void()> on_click, unsigned int size_x, unsigned int size_y, ColorRGB text_color, ColorRGB bg_color)
{
    m_text = text;
    m_onClick = on_click;
    m_sizeX = size_x;
    m_sizeY = size_y;
    m_textColor = text_color;
    m_bgColor = bg_color;
}

void Button::Resize(unsigned int x, unsigned int y)
{
    m_sizeX = x;
    m_sizeY = y;
}

void Button::SetPos(unsigned int x, unsigned int y)
{
    m_posX = x;
    m_posY = y;
}

void Button::SetText(std::string text)
{
    m_text = text;
}

void Button::SetTextColor(ColorRGB color)
{
    m_textColor = color;
}

void Button::SetBgColor(ColorRGB color)
{
    m_bgColor = color;
}

std::string Button::GetText()
{
    return m_text;
}

ColorRGB Button::GetTextColor()
{
    return m_textColor;
}

ColorRGB Button::GetBgColor()
{
    return m_bgColor;
}

void Button::Click()
{
    m_onClick();
}

void Button::Render()
{

}