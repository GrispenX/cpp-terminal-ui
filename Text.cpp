#include "Text.h"
#include <math.h>

Text::Text()
{
    m_text = "";
}

Text::Text(std::string text)
{
    m_text = text;
}

void Text::SetText(std::string text)
{
    m_text = text;
}

void Text::Render()
{
    auto pos = GetPos();
    auto size = GetSize();

    std::cout << GetBackground() << GetForeground();
    for(int y = pos.second; y < pos.second + size.second; y++)
    {
        std::cout << Move(pos.first, y);
        for(int x = 0; x < size.first; x++)
        {
            std::cout << " ";
        }
    }
    
    unsigned int lines = std::ceil((float)m_text.length() / size.first);
    lines = std::min(lines, size.second);
    for(int y = 0; y < lines; y++)
    {
        std::cout << Move(pos.first, pos.second + y) << std::string(m_text, size.first * y, size.first);
    }
    if(m_text.length() > size.first * size.second)
    {
        std::cout << Move(pos.first + size.first - 1, pos.second + size.second - 1) << "…";
    }

    std::cout << ResetStyle();
}