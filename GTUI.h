#ifndef GTUI_H
#define GTUI_H

#include "BaseWidget.h"
#include "InputParser.h"

class GTUI
{
private:
    InputParser m_input_parser;

    bool m_exit;

public:
    void Loop(BaseWidget* root);
    void Exit();
};

#endif