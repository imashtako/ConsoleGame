#include <iostream>
#include <string>

#include <windows.h>

#include "MainCircle.h"
#include "Plane.h"
#include "Background.h"
#include "Hero.h"
#include "InputReader.h"

using namespace std;


int main()
{
    MainCircle circle(60);
    Plane plane(50, 11);
    InputReader input_reader;
    input_reader.Start();
    system("cls");
    plane.HideCursor();
    
    Background background(0, 0);
    Hero hero(4, 7);

    for (int i = 0; true; i++) {
        plane.Clean();
        background.Draw(plane);
        hero.Draw(plane);
        plane.Render();
        cout << i << endl;
        circle.WaitNextFrame();
        hero.CheckInput(input_reader);
        input_reader.CleanBuffer();
    }
}
