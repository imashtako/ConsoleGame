#include <iostream>
#include <string>

#include <windows.h>

#include "MainCircle.h"
#include "Plane.h"
#include "Ground.h"
#include "Hero.h"
#include "InputReader.h"
#include "World.h"
#include "LevelLoader.h"

using namespace std;


int main()
{
    system("cls");

    LevelLoader loader;
    World world = *loader.LoadLevel("level1.txt");
    
    MainCircle circle(20);

    Plane plane(50, 20);
    plane.HideCursor();
    for (int i = 0; true; i++) {
        plane.Update(world);
        plane.Render();
        cout << i << endl;
        world.Update();
        circle.WaitNextFrame();
    }
}
