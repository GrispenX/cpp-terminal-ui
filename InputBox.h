#ifndef INPUTBOX_H
#define INPUTBOX_H

#include "ANSIEscapeSequences.h"
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

    void HandleEvent(std::variant<MouseMoveEvent, MouseButtonEvent, KeyboardEvent> event) override;

    void Render() override;

    InputBox &operator|(const BackgroundRGB &color);
    InputBox &operator|(const ForegroundRGB &color);
};

#endif