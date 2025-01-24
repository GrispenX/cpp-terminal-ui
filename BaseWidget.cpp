#include "BaseWidget.h"

void BaseWidget::SetPos(unsigned int x, unsigned int y)
{
    m_pos = std::make_pair(x, y);
}

void BaseWidget::SetPos(std::pair<unsigned int, unsigned int> pos)
{
    m_pos = pos;
}

void BaseWidget::Resize(unsigned int x, unsigned int y)
{
    m_size = std::make_pair(x, y);
}

void BaseWidget::Resize(std::pair<unsigned int, unsigned int> size)
{
    m_size = size;
}

void BaseWidget::SetForeground(ForegroundRGB color)
{
    m_foregroundRGB = color;
}

void BaseWidget::SetBackground(BackgroundRGB color)
{
    m_backgroundRGB = color;
}

std::pair<unsigned int, unsigned int> BaseWidget::GetPos()
{
    return m_pos;
}

std::pair<unsigned int, unsigned int> BaseWidget::GetSize()
{
    return m_size;
}

ForegroundRGB BaseWidget::GetForeground()
{
    return m_foregroundRGB;
}

BackgroundRGB BaseWidget::GetBackground()
{
    return m_backgroundRGB;
}

// BaseWidget &BaseWidget::operator|(const BackgroundRGB &color)
// {
//     SetBackground(color);
//     return *this;
// }
