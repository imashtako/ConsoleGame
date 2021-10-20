#include <string>
#include <vector>

#include "Hero.h"

using namespace std;

Hero::Hero(int x, int y): x_pos(x), y_pos(y), state(HeroState::RIGHT) {}
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
;
