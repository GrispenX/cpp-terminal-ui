#ifndef FLOATINGCONTAINER_H
#define FLOATINGCONTAINER_H

#include "BaseWidget.h"
#include <vector>
#include <memory>

class FloatingContainer : BaseWidget
{
private:
    std::vector<std::shared_ptr<BaseWidget>> m_children;

public:
    void AddChild(std::shared_ptr<BaseWidget> child);

    void Render() override;
};

#endif