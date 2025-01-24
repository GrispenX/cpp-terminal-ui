#ifndef BORDER_H
#define BORDER_H

#include "BaseWidget.h"
#include <memory>

class Border : public BaseWidget
{
private:
    std::shared_ptr<BaseWidget> m_child;

public:
    void AddChild(std::shared_ptr<BaseWidget> child);

    void Render() override;

    void HandleEvent(std::variant<MouseMoveEvent, MouseButtonEvent, KeyboardEvent> event) override;
};

#endif