#include <string>
#include <vector>

#include "Hero.h"

using namespace std;

Hero::Hero(int x, int y): GameObject(x,y), state(HeroState::RIGHT), IDrawableObject(10) {}
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
}

void Hero::CheckInput()
{
    InputReader* input = InputReader::GetInstance();
    if (input->IsButtonDown(ButtonKey::d)) {
        if (RightIsEmpty())
        {
            x_pos++;
        }
        state = HeroState::RIGHT;
    }
    if (input->IsButtonDown(ButtonKey::a)) {
        if (LeftIsEmpty()) {
            x_pos--;
        }
        state = HeroState::LEFT;
    }
}
void Hero::Gravity()
{
    if (DownIsEmpty()) {
        y_pos++;
    }
}
bool Hero::DownIsEmpty()
{
    for (size_t i = 0; i < x_size; i++) {
        if (world->GetObjectIn(x_pos + i, y_pos + y_size)) {
            return false;
        }
    }
    return true;
}
bool Hero::RightIsEmpty()
{
    for (size_t i = 0; i < y_size; i++) {
        if (world->GetObjectIn(x_pos + x_size, y_pos + i)) {
            return false;
        }
    }
    return true;
}
bool Hero::LeftIsEmpty()
{
    for (size_t i = 0; i < y_size; i++) {
        if (world->GetObjectIn(x_pos - 1 , y_pos + i)) {
            return false;
        }
    }
    return true;
}
bool Hero::InThisPoint(int x, int y)
{
    return x >= x_pos && x < x_pos + (int)x_size && y >= y_pos && y < y_pos + (int)y_size;
}
