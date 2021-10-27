#pragma once

#include "CharMatrix.h"
#include "IDrawableObject.h"
#include "GameObject.h"

class Ground :
    public GameObject,
    public IDrawableObject
{
public:
    Ground(int x, int y, CharMatrix map);
    void Draw(Plane& plane) override;
    bool InThisPoint(int x, int y) override;

private:
    const CharMatrix map;
};

