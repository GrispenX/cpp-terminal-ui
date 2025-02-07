#ifndef VCONTAINER_H
#define VCONTAINER_H

#include "BaseContainer.h"

class VContainer : public BaseContainer
{
    using BaseContainer::BaseContainer;
private:
    void ResolveGeometry() override;
};

#endif