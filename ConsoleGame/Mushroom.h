#pragma once
#include "GameObject.h"
#include "IDrawableObject.h"

enum class MushroomState {
    Left,
    Right
};

class Mushroom :
    public GameObject,
    public IDrawableObject
{
public:
    Mushroom(int x, int y);
    void Draw(Plane& plane) override;
    void Update() override;

private:
    MushroomState state;
};

