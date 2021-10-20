#pragma once
#include "IDrawableObject.h"
#include "InputReader.h"

enum class HeroState {
    LEFT,
    RIGHT,
    JUMPLEFT,
    JUMPRIGHT
};

class Hero :
    public IDrawableObject
{
public:
    Hero(int x, int y);
    void Draw(Plane& plane) override;
    void CheckInput(const InputReader& input_reader);

private:
    int x_pos;
    int y_pos;
    HeroState state;
};

