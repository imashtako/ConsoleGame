#include <iostream>
#include <string>

#include <windows.h>

#include "MainCircle.h"
#include "Plane.h"
#include "Background.h"
#include "Hero.h"

using namespace std;


void HideCursor()
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &info);
}

int main()
{
    MainCircle circle(60);
    Plane plane(50, 11);
    system("cls");
    HideCursor();
    for (int i = 0; true; i++) {
        plane.Clean();
        Background background(0, 0);
        background.Draw(plane);
        Hero human(4, 7);
        human.Draw(plane);
        plane.Render();
        circle.WaitNextFrame();
    }
}
