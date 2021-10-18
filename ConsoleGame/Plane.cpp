#include <iostream>

#include <windows.h>

#include "Plane.h"

using namespace std;

Plane::Plane(int x, int y): x_size(x), y_size(y)
{
    map = vector<vector<char>>(y);
    for (int i = 0; i < y; i++) {
        map[i] = vector<char>(x);
    }
}

void Plane::Clean()
{
    for (int i = 0; i < y_size; i++) {
        for (int j = 0; j < x_size; j++) {
            map[i][j] = ' ';
        }
    }
}

std::string Plane::ToString()
{
    string result = "";
    for (int i = 0; i < y_size; i++) {
        for (int j = 0; j < x_size; j++) {
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

void Plane::MoveCursorTo(int x, int y)
{
    static HANDLE h = NULL;
    if (!h)
        h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD c = { x, y };
    SetConsoleCursorPosition(h, c);
}
