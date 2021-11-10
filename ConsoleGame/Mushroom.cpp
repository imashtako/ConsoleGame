#include "Mushroom.h"

Mushroom::Mushroom(int x, int y) : GameObject(x, y, 8, 4), IDrawableObject(10), state(MushroomState::Right){}

void Mushroom::Draw(Plane& plane)
{
    plane.Insert(x_pos, y_pos, { {
        " ______ ",
        "(_*__*_)",
        "  |  |  ",
        "  |  |  "
        } });
}

void Mushroom::Update()
{
    switch (state)
    {
    case MushroomState::Left:
        if (LeftIsEmpty()) {
            x_pos--;
        }
        else {
            state = MushroomState::Right;
        }
        break;
    case MushroomState::Right:
        if (RightIsEmpty()) {
            x_pos++;
        }
        else {
            state = MushroomState::Left;
        }
        break;
    default:
        break;
    }
}
