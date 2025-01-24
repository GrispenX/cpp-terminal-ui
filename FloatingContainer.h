#ifndef FLOATINGCONTAINER_H
#define FLOATINGCONTAINER_H

#include "BaseWidget.h"
#include <vector>
#include <memory>

class FloatingContainer : BaseWidget
{
private:
    std::vector<BaseWidget*> m_children;

public:
    void AddChild(BaseWidget* child);

    void Render() override;
};

#endif