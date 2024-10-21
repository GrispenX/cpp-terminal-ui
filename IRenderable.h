#ifndef IWIDGET_H
#define IWIDGET_H

class IRenderable
{
public:
    virtual void Render() = 0;
    virtual void Resize(unsigned int x, unsigned int y) = 0;
    virtual void SetPos(unsigned int x, unsigned int y) = 0;
};

#endif