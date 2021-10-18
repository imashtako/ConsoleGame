#include "Background.h"

Background::Background(int x, int y): x_pos(x), y_pos(y) {}
void Background::Draw(Plane& plane)
{
    for (int i = x_pos; i < x_pos + 30; i++) {
        plane.map[y_pos + 10][i] = '~';
    }
}
;
