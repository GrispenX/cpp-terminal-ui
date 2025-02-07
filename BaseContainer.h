#ifndef BASECONTAINER_H
#define BASECONTAINER_H

#include <vector>
#include "BaseWidget.h"

class BaseContainer : public BaseWidget
{
private:
    std::vector<BaseWidget*> m_children;

    virtual void ResolveGeometry() = 0;

public:
    BaseContainer();
    BaseContainer(std::vector<BaseWidget*> children);

    void AddChildren(std::vector<BaseWidget*> children);

    void Render() override;

    void HandleEvent(std::variant<MouseMoveEvent, MouseButtonEvent, KeyboardEvent> event) override;
};

#endif