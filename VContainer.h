#ifndef VCONTAINER_H
#define VCONTAINER_H

#include <vector>
#include <memory>
#include "BaseWidget.h"

class VContainer : public BaseWidget
{
private:
    std::vector<std::shared_ptr<BaseWidget>> m_children;

    void ResolveGeometry();

public:
    void AddChild(std::shared_ptr<BaseWidget> child);

    void Render() override;

    void HandleEvent(std::variant<MouseMoveEvent, MouseButtonEvent, KeyboardEvent> event) override;
};

#endif