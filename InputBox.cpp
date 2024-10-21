#include "InputBox.h"

InputBox::InputBox(std::string text, unsigned int size_x, unsigned int size_y)
{
    m_emptyText = text;
    m_sizeX = size_x;
    m_sizeY = size_y;
}

InputBox::InputBox(std::string text, unsigned int size_x, unsigned int size_y, ColorRGB text_color, ColorRGB bg_color)
{
    m_emptyText = text;
    m_sizeX = size_x;
    m_sizeY = size_y;
    m_textColor = text_color;
    m_bgColor = bg_color;
}

void InputBox::Resize(unsigned int x, unsigned int y)
{
    m_sizeX = x;
    m_sizeY = y;
}

void InputBox::SetPos(unsigned int x, unsigned int y)
{
    m_posX = x;
    m_posY = y;
}

void InputBox::SetEmptyText(std::string text)
{
    m_emptyText = text;
}

void InputBox::SetTextColor(ColorRGB color)
{
    m_textColor = color;
}

void InputBox::SetBgColor(ColorRGB color)
{
    m_bgColor = color;
}

std::string InputBox::GetEmptyText()
{
    return m_emptyText;
}

std::string InputBox::GetInputText()
{
    return m_inputText;
}

ColorRGB InputBox::GetTextColor()
{
    return m_textColor;
}

ColorRGB InputBox::GetBgColor()
{
    return m_bgColor;
}

void InputBox::Render()
{

}