#include "HContainer.h"

void HContainer::ResolveGeometry()
{
    unsigned int child_size_x = GetSize().first / m_children.size();
    unsigned int child_size_y = GetSize().second;
    unsigned int child_pos_x = GetPos().first;
    unsigned int child_pos_y = GetPos().second;

    for(auto child : m_children)
    {
        child->Resize(child_size_x, child_size_y);
        child->SetPos(child_pos_x, child_pos_y);
        child_pos_x += child_size_x;
    }
}

void HContainer::AddChild(std::shared_ptr<BaseWidget> child)
{
    m_children.push_back(child);
}

void HContainer::Render()
{
    ResolveGeometry();
    for(auto child : m_children)
    {
        child->Render();
    }
}

void HContainer::HandleEvent(std::variant<MouseMoveEvent, MouseButtonEvent, KeyboardEvent> event)
{
    for(auto child : m_children)
    {
        child->HandleEvent(event);
    }
}
