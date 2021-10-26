#include "Ground.h"

Ground::Ground(int x, int y): GameObject(x, y) {}
void Ground::Draw(Plane& plane)
{
    plane.Insert(0, 10, { {"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"} });
}
bool Ground::InThisPoint(int x, int y)
{
    return y == 10 && x <= 37;
}
;
