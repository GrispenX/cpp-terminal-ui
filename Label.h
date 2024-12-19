#ifndef LABEL_H
#define LABEL_H

#include "Color.h"
#include "ANSIEscapeSequences.h"
#include "BaseWidget.h"
#include <string>

class Label : public BaseWidget
{
private:
    std::string m_text;

public:
    Label();
    Label(std::string text);

    void SetText(std::string text);

    void Render() override;
};

#endif