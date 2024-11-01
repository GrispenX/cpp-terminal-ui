#ifndef LABEL_H
#define LABEL_H

#include "Color.h"
#include "IRenderable.h"
#include "BaseWidget.h"
#include <string>

class Label : public BaseWidget
{
private:
    std::string m_text;
    ColorRGB m_textColor;
    BgColorRGB m_bgColor;

public:
    Label(std::string text);

    void SetText(std::string text);
    void SetTextColor(ColorRGB color);
    void SetBgColor(BgColorRGB color);

    void Render() override;
};

#endif