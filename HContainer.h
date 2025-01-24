#ifndef HCONTAINER_H
#define HCONTAINER_H

#include <vector>
#include <memory>
#include "BaseWidget.h"

class HContainer : public BaseWidget
{
private:
    std::vector<std::shared_ptr<BaseWidget>> m_children;
    std::shared_ptr<BaseWidget> m_activeChild;

    void ResolveGeometry();

public:
    HContainer();
    HContainer(std::vector<std::shared_ptr<BaseWidget>> children);

    void AddChild(std::shared_ptr<BaseWidget> child);

    void Render() override;

    void HandleEvent(std::variant<MouseMoveEvent, MouseButtonEvent, KeyboardEvent> event) override;
};

#endif