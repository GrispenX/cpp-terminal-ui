#ifndef HCONTAINER_H
#define HCONTAINER_H

#include <vector>
#include <memory>
#include "BaseWidget.h"

class HContainer : public BaseWidget
{
private:
    std::vector<BaseWidget*> m_children;
    BaseWidget* m_activeChild;

    void ResolveGeometry();

public:
    HContainer();

    void AddChild(BaseWidget* child);

    void Render() override;

    void HandleEvent(std::variant<MouseMoveEvent, MouseButtonEvent, KeyboardEvent> event) override;
};

#endif