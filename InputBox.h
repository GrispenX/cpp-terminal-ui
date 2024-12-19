#ifndef INPUTBOX_H
#define INPUTBOX_H

#include "Color.h"
#include "BaseWidget.h"
#include <string>

class InputBox : public BaseWidget
{
private:
    std::string m_hint;
    std::string m_input;

public:
    InputBox();
    InputBox(std::string hint);

    void SetHint(std::string text);

    std::string GetInput();

    void Render() override;
};

#endif