#include "VContainer.h"

void VContainer::ResolveGeometry()
{
    unsigned int child_size_x = m_sizeX;
    unsigned int child_size_y = m_sizeY / m_children.size();
    unsigned int child_pos_x = m_posX;
    unsigned int child_pos_y = m_posY;

    for(auto child : m_children)
    {
        child->Resize(child_size_x, child_size_y);
        child->SetPos(child_pos_x, child_pos_y);
        child_pos_y += child_size_y;
    }
}

void VContainer::SetPos(unsigned int x, unsigned int y)
{
    m_posX = x;
    m_posY = y;
}

void VContainer::Resize(unsigned int x, unsigned int y)
{
    m_sizeX = x;
    m_sizeY = y;
}

void VContainer::AddChild(IRenderable *child)
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
