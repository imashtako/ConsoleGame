#include <string>
#include <vector>

#include "Hero.h"

using namespace std;

Hero::Hero(int x, int y): GameObject(x,y, 6, 3), IDrawableObject(10), state(HeroState::RIGHT) {}
void Hero::Draw(Plane& plane)
{
    vector<string> image;
    switch (state)
    {
    case HeroState::LEFT:
        image = {
        "(._. )",
        "(LL  )",
        " /  \\ "
        };
        break;
    case HeroState::RIGHT:
        image = {
        "( ._.)",
        "(  JJ)",
        " /  \\ "
        };
        break;
    case HeroState::JUMPLEFT:
        break;
    case HeroState::JUMPRIGHT:
        break;
    default:
        break;
    }
    plane.Insert(x_pos, y_pos, image);
}

void Hero::Update()
{
    Gravity();
    CheckInput();
    MoveBySpeed();
}

void Hero::CheckInput()
{
    if (InputReader::IsButtonDown(ButtonKey::d)) {
        if (RightIsEmpty())
        {
            x_pos++;
        }
        state = HeroState::RIGHT;
    }
    if (InputReader::IsButtonDown(ButtonKey::a)) {
        if (LeftIsEmpty()) {
            x_pos--;
        }
        state = HeroState::LEFT;
    }
    if (InputReader::IsButtonDown(ButtonKey::SPACE)) {
        if (!DownIsEmpty()) {
            vertical_speed = -3;
        }
    }
}
void Hero::Gravity()
{
    vertical_speed += 1;
}
void Hero::MoveBySpeed()
{
    if (vertical_speed > 0) {
        vertical_speed = min(vertical_speed, 2);
        for (int i = 0; i < (int)vertical_speed; i++) {
            if (DownIsEmpty()) {
                y_pos++;
            }
            else {
                vertical_speed = 0;
                break;
            }
        }
    }
    else if (vertical_speed < 0) {
        for (int i = 0; i < -(int)vertical_speed; i++) {
            if (UpIsEmpty()) {
                y_pos--;
            }
            else {
                vertical_speed = 0;
                break;
            }
        }
    }
}
