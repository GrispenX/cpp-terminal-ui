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

std::string InputBox::GetInput()
{
    return m_input;
}

void InputBox::Render()
{

}