#include "BaseContainer.h"

BaseContainer::BaseContainer()
{
}

BaseContainer::BaseContainer(std::vector<BaseWidget *> children)
{
    m_children = children;
}

void BaseContainer::AddChildren(std::vector<BaseWidget *> children)
{
    for(auto child : children)
    {
        m_children.push_back(child);
    }
}

void BaseContainer::Render()
{
    ResolveGeometry();
    for(auto child : m_children)
    {
        child->Render();
    }
}

void BaseContainer::HandleEvent(std::variant<MouseMoveEvent, MouseButtonEvent, KeyboardEvent> event)
{
    if(std::holds_alternative<MouseButtonEvent>(event))
    {
        auto e = std::get<MouseButtonEvent>(event);
        auto pos = GetPos();
        auto size = GetSize();
        SetActive((e.pos.first >= pos.first && e.pos.first <= pos.first + size.first - 1 &&
                   e.pos.second >= pos.second && e.pos.second <= pos.second + size.second - 1));
        for(auto child : m_children)
        {
            pos = child->GetPos();
            size = child->GetSize();
            if((e.pos.first >= pos.first && e.pos.first <= pos.first + size.first - 1 &&
               e.pos.second >= pos.second && e.pos.second <= pos.second + size.second - 1) || child->IsActive())
            {
                child->HandleEvent(e);
            }
        }
    }
    else if(std::holds_alternative<KeyboardEvent>(event))
    {
        auto e = std::get<KeyboardEvent>(event);
        for(auto child : m_children)
        {
            if(child->IsActive())
            {
                child->HandleEvent(e);
            }
        }
    }
}
