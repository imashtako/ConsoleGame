#include <iostream>
#include <string>

#include <windows.h>

#include "MainCircle.h"
#include "Plane.h"
#include "Ground.h"
#include "Hero.h"
#include "InputReader.h"
#include "World.h"

using namespace std;


int main()
{
    system("cls");


    MainCircle circle(60);

    InputReader input_reader;
    input_reader.Start();

    World world;
    Ground* background = new Ground(0, 0);
    world.AddObject(background);
    Hero* hero = new Hero(4, 7);
    world.AddObject(hero);
    Plane plane(50, 11);
    plane.HideCursor();

    for (int i = 0; true; i++) {
        plane.Update(world);
        plane.Render();
        cout << i << endl;
        circle.WaitNextFrame();
        hero->CheckInput(input_reader);
        input_reader.CleanBuffer();
    }
}
