#pragma once
#include "IDrawableObject.h"
class Human :
    public IDrawableObject
{
public:
    Human(int x, int y);
    void Draw(Plane& plane) override;

private:
    const int x_pos;
    const int y_pos;
};

