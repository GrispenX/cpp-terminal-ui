#ifndef BASEWIDGET_H
#define BASEWIDGET_H

#include "InputEvents.h"
#include <utility>

class BaseWidget
{
private:
    std::pair<unsigned int, unsigned int> m_pos;
    std::pair<unsigned int, unsigned int> m_size;

public:
    void SetPos(unsigned int x, unsigned int y);
    void SetPos(std::pair<unsigned int, unsigned int> pos);
    void Resize(unsigned int x, unsigned int y);
    void Resize(std::pair<unsigned int, unsigned int> size);

    std::pair<unsigned int, unsigned int> GetPos();
    std::pair<unsigned int, unsigned int> GetSize();

    virtual void Render() = 0;

    virtual void HandleEvent(MouseMoveEvent event) = 0;
    virtual void HandleEvent(MouseButtonEvent event) = 0;
    virtual void HandleEvent(KeyboardEvent event) = 0;
};

#endif