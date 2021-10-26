#include <string>
#include <vector>

#include "Hero.h"

using namespace std;

Hero::Hero(int x, int y): GameObject(x,y), state(HeroState::RIGHT) {}
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

void Hero::Update(const Plane& plane)
{
}

void Hero::CheckInput(const InputReader& input_reader)
{
    if (input_reader.IsButtonDown(ButtonKey::d)) {
        x_pos++;
        state = HeroState::RIGHT;
    }
    if (input_reader.IsButtonDown(ButtonKey::a)) {
        x_pos--;
        state = HeroState::LEFT;
    }
}
bool Hero::InThisPoint(int x, int y)
{
    return x >= x_pos && x < x_pos + (int)x_size && y >= y_pos && y < y_pos + (int)y_size;
}
