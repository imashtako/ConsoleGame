#pragma once

#include "IDrawableObject.h"

class Background :
    public IDrawableObject
{
public:
    Background(int x, int y);
    void Draw(Plane& plane) override;

private:
    const int x_pos;
    const int y_pos;
};

