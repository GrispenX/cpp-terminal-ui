#ifndef WINDOW_H
#define WINDOW_H

#include <utility>
#include <memory>
#include <functional>
#include <iostream>
#include "BaseWidget.h"
#include "ANSIEscapeSequences.h"

class Window
{
private:
    std::pair<unsigned int, unsigned int> m_pos;
    std::pair<unsigned int, unsigned int> m_size;

    std::string m_title;

    std::shared_ptr<BaseWidget> m_child;

    void RenderFrame();

public:
    Window() = delete;
    Window(std::shared_ptr<BaseWidget> child, std::pair<unsigned int, unsigned int> size, std::pair<unsigned int, unsigned int> pos);

    void SetPos(unsigned int x, unsigned int y);
    void SetPos(std::pair<unsigned int, unsigned int> pos);
    void Resize(unsigned int x, unsigned int y);
    void Resize(std::pair<unsigned int, unsigned int> size);

    void SetTitle(std::string title);

    void Render();
};

#endif