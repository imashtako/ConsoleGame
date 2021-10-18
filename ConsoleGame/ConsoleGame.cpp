#include <iostream>
#include "MainCircle.h"
#include "Plane.h"
#include "Background.h"
#include "Human.h"

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
        Human human(4, 7);
        human.Draw(plane);
        plane.Render();
        cout << i << endl;
        circle.WaitNextFrame();
    }
}
