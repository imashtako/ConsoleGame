#pragma once
#include "IDrawableObject.h"
class Hero :
    public IDrawableObject
{
public:
    Hero(int x, int y);
    void Draw(Plane& plane) override;

private:
    const int x_pos;
    const int y_pos;
};

