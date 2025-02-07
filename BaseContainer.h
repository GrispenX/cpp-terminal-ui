#ifndef BASECONTAINER_H
#define BASECONTAINER_H

#include <vector>
#include "BaseWidget.h"

class BaseContainer : public BaseWidget
{
private:
    virtual void ResolveGeometry() = 0;

protected:
    std::vector<BaseWidget*> m_children;

public:
    BaseContainer();
    BaseContainer(std::vector<BaseWidget*> children);

    void AddChildren(std::vector<BaseWidget*> children);

    void Render() override;

    void HandleEvent(std::variant<MouseMoveEvent, MouseButtonEvent, KeyboardEvent> event) override;
};

#endif