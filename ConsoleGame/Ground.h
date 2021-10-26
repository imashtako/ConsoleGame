#pragma once

#include "IDrawableObject.h"
#include "GameObject.h"

class Ground :
    public GameObject,
    public IDrawableObject
{
public:
    Ground(int x, int y);
    void Draw(Plane& plane) override;
    bool InThisPoint(int x, int y) override;
};

