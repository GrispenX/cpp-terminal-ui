#ifndef HCONTAINER_H
#define HCONTAINER_H

#include "BaseContainer.h"

class HContainer : public BaseContainer
{
private:
    void ResolveGeometry() override;
};

#endif