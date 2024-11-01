#include "Label.h"

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

}