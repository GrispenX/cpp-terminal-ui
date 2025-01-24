#ifndef VCONTAINER_H
#define VCONTAINER_H

#include <vector>
#include <memory>
#include "BaseWidget.h"

class VContainer : public BaseWidget
{
private:
    std::vector<BaseWidget*> m_children;
    BaseWidget* m_activeChild;

    void ResolveGeometry();

public:
    void AddChild(BaseWidget* child);

    void Render() override;

    void HandleEvent(std::variant<MouseMoveEvent, MouseButtonEvent, KeyboardEvent> event) override;
};

#endif