#include <iostream>

#include <windows.h>

#include "Plane.h"

using namespace std;

Plane::Plane(size_t x, size_t y): map(x, y)
{
    Clean();
}

void Plane::Clean()
{
    for (size_t i = 0; i < map.size_y; i++) {
        for (size_t j = 0; j < map.size_x; j++) {
            map[i][j] = ' ';
        }
    }
}

std::string Plane::ToString()
{
    string result = "";
    for (size_t i = 0; i < map.size_y; i++) {
        for (size_t j = 0; j < map.size_x; j++) {
            result += map[i][j];
        }
        result += '\n';
    }
    return result;
}

void Plane::Render()
{
    MoveCursorTo(0, 0);
    cout << ToString() << endl;
}

void Plane::Insert(size_t x, size_t y, CharMatrix&& matrix)
{
    for (size_t i = 0; i < matrix.size_y; i++) {
        for (size_t j = 0; j < matrix.size_x; j++) {
            if (y + i < map.size_y && x + j < map.size_x)
            {
                map[y + i][x + j] = matrix[i][j];
            }
        }
    }
}

void Plane::MoveCursorTo(short x, short y)
{
    static HANDLE h = NULL;
    if (!h)
        h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD c = { x, y };
    SetConsoleCursorPosition(h, c);
}
