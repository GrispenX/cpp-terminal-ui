#ifndef HCONTAINER_H
#define HCONTAINER_H

#include <vector>
#include <memory>
#include "BaseWidget.h"

class HContainer : public BaseWidget
{
private:
    std::vector<std::shared_ptr<BaseWidget>> m_children;

    void ResolveGeometry();

public:
    void AddChild(std::shared_ptr<BaseWidget> child);

    void Render() override;
};

#endif