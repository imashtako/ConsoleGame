#include "Human.h"

Human::Human(int x, int y): x_pos(x), y_pos(y) {}
void Human::Draw(Plane& plane)
{
    plane.map[y_pos][x_pos + 1] = '*';
    plane.map[y_pos + 1][x_pos] = '/';
    plane.map[y_pos + 1][x_pos + 1] = '|';
    plane.map[y_pos + 1][x_pos + 2] = '\\';
    plane.map[y_pos + 2][x_pos] = '|';
    plane.map[y_pos + 2][x_pos] = '/';
    plane.map[y_pos + 2][x_pos + 2] = '\\';
}
;
