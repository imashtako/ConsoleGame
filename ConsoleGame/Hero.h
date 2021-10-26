#pragma once
#include "IDrawableObject.h"
#include "InputReader.h"
#include "GameObject.h"

enum class HeroState {
    LEFT,
    RIGHT,
    JUMPLEFT,
    JUMPRIGHT
};

class Hero :
    public GameObject,
    public IDrawableObject
{
public:
    Hero(int x, int y);
    void Draw(Plane& plane) override;
    void Update(const Plane& plane);
    void CheckInput(const InputReader& input_reader);
    bool InThisPoint(int x, int y) override;

private:
    const size_t x_size = 6;
    const size_t y_size = 3;
    HeroState state;
};

