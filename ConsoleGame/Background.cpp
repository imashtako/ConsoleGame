#include "Background.h"

Background::Background(int x, int y): x_pos(x), y_pos(y) {}
void Background::Draw(Plane& plane)
{
    plane.Insert(0, 10, { {"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"} });
}
;
