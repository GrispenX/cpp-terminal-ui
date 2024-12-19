#ifndef BASEWIDGET_H
#define BASEWIDGET_H

#include "InputEvents.h"
#include "Color.h"
#include <utility>
#include <vector>
#include <functional>
#include <variant>

class BaseWidget
{
private:
    std::pair<unsigned int, unsigned int> m_pos;
    std::pair<unsigned int, unsigned int> m_size;

    ForegroundRGB m_foregroundRGB;
    BackgroundRGB m_backgroundRGB;

public:
    void SetPos(unsigned int x, unsigned int y);
    void SetPos(std::pair<unsigned int, unsigned int> pos);
    void Resize(unsigned int x, unsigned int y);
    void Resize(std::pair<unsigned int, unsigned int> size);
    void SetForeground(ForegroundRGB color);
    void SetBackground(BackgroundRGB color);

    std::pair<unsigned int, unsigned int> GetPos();
    std::pair<unsigned int, unsigned int> GetSize();
    ForegroundRGB GetForeground();
    BackgroundRGB GetBackground();

    virtual void Render() = 0;

    virtual void HandleEvent(std::variant<MouseMoveEvent, MouseButtonEvent, KeyboardEvent> event) {};
};

#endif