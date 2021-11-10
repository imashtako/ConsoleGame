#include "Ground.h"

Ground::Ground(int x, int y, CharMatrix matrix): GameObject(x, y, matrix.size_x, matrix.size_y), IDrawableObject(0), map(matrix) {}
void Ground::Draw(Plane& plane)
{
    plane.Insert(x_pos, y_pos, map);
}
bool Ground::InThisPoint(int x, int y)
{
    if (x < x_pos || x >= x_pos + (int)map.size_x || y < y_pos || y >= y_pos + (int)map.size_y) {
        return false;
    }
    return map[y - y_pos][x - x_pos] == '~';
}
;
