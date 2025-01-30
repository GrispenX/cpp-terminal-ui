#include "Border.h"
#include "ANSIEscapeSequences.h"

Border::Border(BorderStyle style, BaseWidget* child)
{
    m_style = style;
    m_child = child;
}

void Border::SetStyle(BorderStyle style)
{
    m_style = style;
}

void Border::Render()
{
    auto pos = GetPos();
    auto size = GetSize();

    m_child->Resize(size.first - 2, size.second - 2);
    m_child->SetPos(pos.first + 1, pos.second + 1);

    std::cout << GetBackground() << GetForeground();

    std::cout << Move(pos.first, pos.second) << m_style.top_left_corner;
    for(int x = 0; x < size.first - 2; x++) std::cout << m_style.horizontal;
    std::cout << m_style.top_right_corner;
    for(int y = 0; y < size.second - 2; y++) 
    {
        std::cout << Move(pos.first, pos.second + y + 1) << m_style.vertical;
        std::cout << Move(pos.first + size.first - 1, pos.second + y + 1) << m_style.vertical;
    }
    std::cout << Move(pos.first, pos.second + size.second - 1) << m_style.bottom_left_corner;
    for(int x = 0; x < size.first - 2; x++) std::cout << m_style.horizontal;
    std::cout << m_style.bottom_right_corner;

    std::cout << ResetStyle();

    m_child->Render();

}

void Border::HandleEvent(std::variant<MouseMoveEvent, MouseButtonEvent, KeyboardEvent> event)
{
    m_child->HandleEvent(event);
}

const BorderStyle RectangularBorderStyle
{
    .vertical =            "│",
    .horizontal =          "─",
    .top_left_corner =     "┌",
    .top_right_corner =    "┐",
    .bottom_left_corner =  "└",
    .bottom_right_corner = "┘"
};
const BorderStyle RectangularBoldBorderStyle
{
    .vertical =            "┃",
    .horizontal =          "━",
    .top_left_corner =     "┏",
    .top_right_corner =    "┓",
    .bottom_left_corner =  "┗",
    .bottom_right_corner = "┛"
};
const BorderStyle RoundedBorderStyle
{
    .vertical =            "│",
    .horizontal =          "─",
    .top_left_corner =     "╭",
    .top_right_corner =    "╮",
    .bottom_left_corner =  "╰",
    .bottom_right_corner = "╯"
};
const BorderStyle DoubleBorderStyle
{
    .vertical =            "║",
    .horizontal =          "═",
    .top_left_corner =     "╔",
    .top_right_corner =    "╗",
    .bottom_left_corner =  "╚",
    .bottom_right_corner = "╝"
};