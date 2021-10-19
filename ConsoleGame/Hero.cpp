#include <string>
#include <vector>

#include "Hero.h"

using namespace std;

Hero::Hero(int x, int y): x_pos(x), y_pos(y) {}
void Hero::Draw(Plane& plane)
{
    plane.Insert(x_pos, y_pos, { {
        " * ",
        "/|\\",
        " | ",
        "/ \\",
    } });
   
}
;
