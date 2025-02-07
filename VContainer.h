#ifndef VCONTAINER_H
#define VCONTAINER_H

#include "BaseContainer.h"

class VContainer : public BaseContainer
{
private:
    void ResolveGeometry() override;
};

#endif