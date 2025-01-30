#ifndef BORDER_H
#define BORDER_H

#include "BaseWidget.h"

struct BorderStyle
{
    std::string vertical;
    std::string horizontal;
    std::string top_left_corner;
    std::string top_right_corner;
    std::string bottom_left_corner;
    std::string bottom_right_corner;
};

class Border : public BaseWidget
{
private:
    BaseWidget* m_child;

    BorderStyle m_style;

public:
    Border() = delete;
    Border(BorderStyle style, BaseWidget* child);

    void SetStyle(BorderStyle style);

    void Render() override;

    void HandleEvent(std::variant<MouseMoveEvent, MouseButtonEvent, KeyboardEvent> event) override;
};

extern const BorderStyle RectangularBorderStyle;
extern const BorderStyle RectangularBoldBorderStyle;
extern const BorderStyle RoundedBorderStyle;
extern const BorderStyle DoubleBorderStyle;

#endif