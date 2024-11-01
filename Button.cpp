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

}