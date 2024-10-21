#ifndef LABEL_H
#define LABEL_H

#include "Color.h"
#include "IRenderable.h"
#include <string>

class Label : public IRenderable
{
private:
    unsigned int m_posX;
    unsigned int m_posY;
    unsigned int m_sizeX;
    unsigned int m_sizeY;

    std::string m_text;
    ColorRGB m_textColor;
    ColorRGB m_bgColor;

public:
    Label() = delete;
    Label(std::string text, unsigned int size_x, unsigned int size_y);
    Label(std::string text, unsigned int size_x, unsigned int size_y, ColorRGB text_color, ColorRGB bg_color);

    void Resize(unsigned int x, unsigned int y) override;
    void SetPos(unsigned int x, unsigned int y) override;

    void SetText(std::string text);
    void SetTextColor(ColorRGB color);
    void SetBgColor(ColorRGB color);
    std::string GetText();
    ColorRGB GetTextColor();
    ColorRGB GetBgColor();

    void Render() override;
};

#endif