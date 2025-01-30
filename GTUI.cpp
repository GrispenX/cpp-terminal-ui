#include "GTUI.h"
#include "ANSIEscapeSequences.h"

void GTUI::Loop(BaseWidget* root)
{
    m_exit = false;    
    system("stty raw");
    std::cout << AltBuffer(true) << ResetStyle() << Clear() << ShowCursor(false) << Mouse(true) << MouseURXVT(true) << MouseSGR(true);
    std::cout.flush();
    while(!m_exit)
    {
        auto event = m_input_parser.ParseChar();
        if(event.has_value())
        {
            root->HandleEvent(event.value());
            std::cout << Clear();
            root->Render();
            std::cout << Move(0, 20) << std::flush; //TODO: change this
        }
    }
    std::cout << AltBuffer(false) << ResetStyle() << Clear() << ShowCursor(true) << Mouse(false) << MouseURXVT(false) << MouseSGR(false);
    system("stty cooked");
    std::cout << Move(0, 0);
}

void GTUI::Exit()
{
    m_exit = true;
}