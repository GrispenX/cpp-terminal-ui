#ifndef INPUTBOX_H
#define INPUTBOX_H

#include "Color.h"
#include "IRenderable.h"
#include <string>

class InputBox : public IRenderable
{
private:
    unsigned int m_posX;
    unsigned int m_posY;
    unsigned int m_sizeX;
    unsigned int m_sizeY;

    std::string m_emptyText;
    std::string m_inputText;
    ColorRGB m_textColor;
    ColorRGB m_bgColor;

public:
    InputBox() = delete;
    InputBox(std::string text, unsigned int size_x, unsigned int size_y);
    InputBox(std::string text, unsigned int size_x, unsigned int size_y, ColorRGB text_color, ColorRGB bg_color);

    void Resize(unsigned int x, unsigned int y) override;
    void SetPos(unsigned int x, unsigned int y) override;

    void SetEmptyText(std::string text);
    void SetTextColor(ColorRGB color);
    void SetBgColor(ColorRGB color);
    std::string GetEmptyText();
    std::string GetInputText();
    ColorRGB GetTextColor();
    ColorRGB GetBgColor();

    void Render() override;
};

#endif