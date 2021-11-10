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
    void Update() override;

private:
    int vertical_speed = 0;
    HeroState state;
    void CheckInput();
    void Gravity();
    void MoveBySpeed();
};

