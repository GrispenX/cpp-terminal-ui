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
    ColorRGB m_textColor;
    BgColorRGB m_bgColor;

    std::vector<std::pair<MouseButtonEvent, std::function<void()>>> m_onButtonEvents;

public:
    Button();

    void SetText(std::string text);
    void SetTextColor(ColorRGB color);
    void SetBgColor(BgColorRGB color);

    void AddEvent(MouseButtons button, MouseButtonState state, std::function<void()> on_event);

    void HandleEvent(MouseButtonEvent event) override;

    void Render() override;
};

#endif