#include "Spacer.h"

void Spacer::Render()
{
    auto pos = GetPos();
    auto size = GetSize();

    std::cout << GetBackground() << GetForeground();
    for(int y = pos.second; y < pos.second + size.second; y++)
    {
        std::cout << Move(pos.first, y);
        for(int x = pos.first; x < pos.first + size.first; x++)
        {
            std::cout << " ";
        }
    }

    std::cout << ResetStyle();
}