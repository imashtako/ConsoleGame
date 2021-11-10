
#include "World.h"
#include "GameObject.h"

bool GameObject::InThisPoint(int x, int y)
{
    return x >= x_pos && x < x_pos + (int)x_size && y >= y_pos && y < y_pos + (int)y_size;
}

void GameObject::Update()
{
}

GameObject::GameObject(int x, int y, size_t _x_size, size_t _y_size): x_pos(x), y_pos(y), x_size(_x_size), y_size(_y_size)
{
}

bool GameObject::DownIsEmpty()
{
    for (size_t i = 0; i < x_size; i++) {
        if (world->GetObjectIn(x_pos + i, y_pos + y_size)) {
            return false;
        }
    }
    return true;
}
bool GameObject::UpIsEmpty()
{
    for (size_t i = 0; i < x_size; i++) {
        if (world->GetObjectIn(x_pos + i, y_pos - 1)) {
            return false;
        }
    }
    return true;
}
bool GameObject::RightIsEmpty()
{
    for (size_t i = 0; i < y_size; i++) {
        if (world->GetObjectIn(x_pos + x_size, y_pos + i)) {
            return false;
        }
    }
    return true;
}
bool GameObject::LeftIsEmpty()
{
    for (size_t i = 0; i < y_size; i++) {
        if (world->GetObjectIn(x_pos - 1, y_pos + i)) {
            return false;
        }
    }
    return true;
}
