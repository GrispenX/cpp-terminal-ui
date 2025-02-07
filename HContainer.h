#ifndef HCONTAINER_H
#define HCONTAINER_H

#include "BaseContainer.h"

class HContainer : public BaseContainer
{
    using BaseContainer::BaseContainer;
private:
    void ResolveGeometry() override;
};

#endif