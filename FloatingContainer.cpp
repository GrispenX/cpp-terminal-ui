#include "FloatingContainer.h"

void FloatingContainer::AddChild(std::shared_ptr<BaseWidget> child)
{
    m_children.push_back(child);
}

void FloatingContainer::Render()
{
    for(auto child : m_children)
    {
        child->Render();
    }
}