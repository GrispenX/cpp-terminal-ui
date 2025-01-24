#include "FloatingContainer.h"

void FloatingContainer::AddChild(BaseWidget* child)
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