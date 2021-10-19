#include <iostream>
#include "MainCircle.h"
#include "Plane.h"
#include "Background.h"
#include "Hero.h"
#include <string>

using namespace std;


int main()
{
    MainCircle circle(60);
    Plane plane(50, 11);
    system("cls");
    for (int i = 0; true; i++) {
        plane.Clean();
        Background background(0, 0);
        background.Draw(plane);
        Hero human(4, 6);
        human.Draw(plane);
        plane.Render();
        circle.WaitNextFrame();
    }
}
