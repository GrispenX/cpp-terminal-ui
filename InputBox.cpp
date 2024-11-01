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

void InputBox::SetTextColor(ColorRGB color)
{
    m_textColor = color;
}

void InputBox::SetBgColor(BgColorRGB color)
{
    m_bgColor = color;
}

std::string InputBox::GetInput()
{
    return m_input;
}

void InputBox::Render()
{

}