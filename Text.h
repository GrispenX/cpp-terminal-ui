#ifndef TEXT_H
#define TEXT_H

#include "ANSIEscapeSequences.h"
#include "BaseWidget.h"

class Text : public BaseWidget
{
private:
    std::string m_text;

public:
    Text();
    Text(std::string text);

    void SetText(std::string text);

    void Render() override;
};

#endif