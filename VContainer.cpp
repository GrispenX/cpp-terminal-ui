#include "VContainer.h"

void VContainer::ResolveGeometry()
{
    unsigned int child_size_x = GetSize().first;
    unsigned int child_size_y = GetSize().second / m_children.size();
    unsigned int child_pos_x = GetPos().first;
    unsigned int child_pos_y = GetPos().second;

    for(auto child : m_children)
    {
        child->Resize(child_size_x, child_size_y);
        child->SetPos(child_pos_x, child_pos_y);
        child_pos_y += child_size_y;
    }
}

void VContainer::AddChild(BaseWidget* child)
{
    m_children.push_back(child);
}

void VContainer::Render()
{
    ResolveGeometry();
    for(auto child : m_children)
    {
        child->Render();
    }
}

void VContainer::HandleEvent(std::variant<MouseMoveEvent, MouseButtonEvent, KeyboardEvent> event)
{
    // if(std::holds_alternative<MouseButtonEvent>(event))
    // {
    //     auto e = std::get<MouseButtonEvent>(event);
    //     for(auto child : m_children)
    //     {
    //         auto pos = child->GetPos();
    //         auto size = child->GetSize();

    //         if(e.pos.first >= pos.first && e.pos.first <= pos.first + size.first - 1 &&
    //            e.pos.second >= pos.second && e.pos.second <= pos.second + size.second - 1)
    //         {
    //             m_activeChild = child;
    //             child->HandleEvent(e);
    //         }
    //     }
    // }
    // else if(std::holds_alternative<KeyboardEvent>(event))
    // {
    //     auto e = std::get<KeyboardEvent>(event);
    //     m_activeChild->HandleEvent(e);
    // }

    for(auto child : m_children)
    {
        child->HandleEvent(event);
    }
}
