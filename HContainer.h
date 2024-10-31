#ifndef HCONTAINER_H
#define HCONTAINER_H

#include <vector>
#include "IRenderable.h"

class HContainer : IRenderable
{
private:
    unsigned int m_posX;
    unsigned int m_posY;
    unsigned int m_sizeX;
    unsigned int m_sizeY;

    std::vector<IRenderable*> m_children;

    void ResolveGeometry();

public:
    void SetPos(unsigned int x, unsigned int y);
    void Resize(unsigned int x, unsigned int y);

    void AddChild(IRenderable* child);

    void Render() override;
};

#endif