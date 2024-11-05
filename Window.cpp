#include "Window.h"

void Window::RenderFrame()
{
    std::cout << Move(m_pos.first, m_pos.second) << "╭";
    for(int i = 0; i < m_size.first - 3; i++)
    {
        std::cout << "─";
    }
    std::cout << "×" << "╮";
    for(int i = 0; i < m_size.second - 2; i++)
    {
        std::cout << Move(m_pos.first, m_pos.second + i + 1) << "│" << Move(m_pos.first + m_size.first - 1, m_pos.second + i + 1) << "│";
    }
    std::cout << Move(m_pos.first, m_pos.second + m_size.second - 1) << "╰";
    for(int i = 0; i < m_size.first - 2; i++)
    {
        std::cout << "─";
    }
    std::cout << "┛";

    std::cout << Move(m_pos.first, m_pos.second + 2) << "├";
    for(int i = 0; i < m_size.first - 2; i++)
    {
        std::cout << "─";
    }
    std::cout << "┤";

    std::string title_to_render = m_title;
    if(title_to_render.length() > m_size.first - 2)
    {
        title_to_render = title_to_render.substr(0, m_size.first - 4) + ".."; //…
    }
    std::cout << Move(m_pos.first + 1 + (m_size.first - title_to_render.length() - 2) / 2, m_pos.second + 1) << title_to_render;
}

Window::Window(std::shared_ptr<BaseWidget> child, std::pair<unsigned int, unsigned int> size, std::pair<unsigned int, unsigned int> pos)
{
    m_child = child;
    SetPos(pos);
    Resize(size);
}

void Window::SetPos(unsigned int x, unsigned int y)
{
    m_pos = std::make_pair(x, y);
    m_child->SetPos(x + 1, y + 3);
}

void Window::SetPos(std::pair<unsigned int, unsigned int> pos)
{
    m_pos = pos;
    m_child->SetPos(std::make_pair(pos.first + 1, pos.second + 3));
}

void Window::Resize(unsigned int x, unsigned int y)
{
    m_size = std::make_pair(x, y);
    m_child->Resize(x - 2, y - 4);
}

void Window::Resize(std::pair<unsigned int, unsigned int> size)
{
    m_size = size;
    m_child->Resize(std::make_pair(size.first - 2, size.second - 4));
}

void Window::SetTitle(std::string title)
{
    m_title = title;
}

void Window::Render()
{
    RenderFrame();
    m_child->Render();
}