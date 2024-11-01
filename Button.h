#ifndef BUTTON_H
#define BUTTON_H

#include "Color.h"
#include "BaseWidget.h"
#include <string>
#include <functional>

class Button : public BaseWidget
{
private:
    std::string m_text;
    ColorRGB m_textColor;
    BgColorRGB m_bgColor;

    std::function<void()> m_onClick;
    
public:
    Button();
    Button(std::string text, std::function<void()> on_click);

    void SetText(std::string text);
    void SetTextColor(ColorRGB color);
    void SetBgColor(BgColorRGB color);

    void OnClick(std::function<void()> on_click);

    void Render() override;
};

#endif