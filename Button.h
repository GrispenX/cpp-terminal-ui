#ifndef BUTTON_H
#define BUTTON_H

#include "Color.h"
#include "BaseWidget.h"
#include "ANSIEscapeSequences.h"
#include <string>
#include <functional>

class Button : public BaseWidget
{
private:
    std::string m_text;

    std::vector<std::pair<MouseButtonEvent, std::function<void()>>> m_onButtonEvents;

public:
    Button();

    void SetText(std::string text);

    void AddEvent(MouseButtons button, MouseButtonState state, std::function<void()> on_event);

    void HandleEvent(std::variant<MouseMoveEvent, MouseButtonEvent, KeyboardEvent> event) override;

    void Render() override;
};

#endif