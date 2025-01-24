#include "EventHandler.h"
#include <termios.h>
#include <iostream>

EventHandler::EventHandler()
{
    m_exit = false;
}

void EventHandler::AddWindow(std::shared_ptr<Window> window)
{
    m_handledWindows.push_back(window);
}

void EventHandler::SetCanonical()
{
    struct termios tio;
    tcgetattr(STDIN_FILENO, &tio);
    tio.c_lflag ^= (ICANON);
    tcsetattr(STDIN_FILENO, TCSANOW, &tio);
}

void EventHandler::SetNonCanonical()
{
    struct termios tio;
    tcgetattr(STDIN_FILENO, &tio);
    tio.c_lflag &= (~ICANON);
    tcsetattr(STDIN_FILENO, TCSANOW, &tio);
}

void EventHandler::Loop()
{
    SetNonCanonical();

    std::cout << Mouse(true) << MouseSGR(true);

    while(!m_exit)
    {
        int len = read(STDIN_FILENO, &m_buffer, sizeof(m_buffer));
        std::string input(m_buffer, len);

        for(auto window : m_handledWindows)
        {
            
        }
    }

    SetCanonical();

    m_exit = false;
}

void EventHandler::Exit()
{
    m_exit = true;
}
