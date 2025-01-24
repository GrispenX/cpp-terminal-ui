#include "Border.h"
#include "ANSIEscapeSequences.h"

void Border::AddChild(std::shared_ptr<BaseWidget> child)
{
    m_child = child;
}

void Border::Render()
{

    auto pos = GetPos();
    auto size = GetSize();

    m_child->Resize(size.first - 2, size.second - 2);
    m_child->SetPos(pos.first + 1, pos.second + 1);

    std::cout << GetBackground() << GetForeground();

    std::cout << Move(pos.first, pos.second) << "╭";
    for(int x = 0; x < size.first - 2; x++) std::cout << "─";
    std::cout << "╮";
    for(int y = 0; y < size.second - 2; y++) std::cout << Move(pos.first, pos.second + y + 1) << "│" << Move(pos.first + size.first - 1, pos.second + y + 1) << "│";
    std::cout << Move(pos.first, pos.second + size.second - 1) << "╰";
    for(int x = 0; x < size.first - 2; x++) std::cout << "─";
    std::cout << "╯";

    std::cout << ResetStyle();

    m_child->Render();

}

void Border::HandleEvent(std::variant<MouseMoveEvent, MouseButtonEvent, KeyboardEvent> event)
{
    m_child->HandleEvent(event);
}
