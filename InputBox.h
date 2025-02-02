#ifndef INPUTBOX_H
#define INPUTBOX_H

#include "ANSIEscapeSequences.h"
#include "BaseWidget.h"
#include <string>
#include <regex>

const std::regex VALIDATOR_DOUBLE{"^-?[0-9]+[.]?[0-9]*$"};
const std::regex VALIDATOR_INT{"^[0-9]*$"};

class InputBox : public BaseWidget
{
private:
    std::string m_hint;
    std::string m_input;

    BackgroundRGB m_activeBackgroundRGB;
    ForegroundRGB m_activeForegroundRGB;
    ForegroundRGB m_hintForeground;

    std::regex s_validator;

public:
    InputBox() = delete;
    InputBox(std::string hint);
    InputBox(std::string hint, std::regex validator);

    void SetHint(std::string hint);

    void SetActiveBackground(BackgroundRGB color);
    void SetActiveForeground(ForegroundRGB color);
    void SetHintForeground(ForegroundRGB color);
    BackgroundRGB GetActiveBackground();
    ForegroundRGB GetActiveForeground();
    ForegroundRGB GetHintForeground();

    std::string GetInput();

    void HandleEvent(std::variant<MouseMoveEvent, MouseButtonEvent, KeyboardEvent> event) override;

    void Render() override;

    InputBox &operator|(const BackgroundRGB &color);
    InputBox &operator|(const ForegroundRGB &color);
};

#endif