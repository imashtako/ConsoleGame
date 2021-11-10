#include <fstream>
#include <iostream>

#include "LevelLoader.h"
#include "Ground.h"
#include "Hero.h"
#include "Mushroom.h"

using namespace std;

enum class Symbol {
    GROUND = '~',
    HERO = '$',
    MUSROOM = '*',
};

World* LevelLoader::LoadLevel(std::string path)
{
    vector<string> text = ReadFile(path);

    size_t y_ground_start = SIZE_MAX;
    size_t x_ground_start = SIZE_MAX;
    size_t y_ground_end = 0;
    size_t x_ground_end = 0;

    for (size_t i = 0; i < text.size();i++){
        string line = text[i];
        int pos = line.find((char)Symbol::GROUND);
        if (pos > -1) {
            y_ground_start = min(y_ground_start, i);
            x_ground_start = min(x_ground_start, (size_t)pos);
            y_ground_end = max(y_ground_end, i);
            int last = pos;
            while (true) {
                pos = line.substr(last + 1).find((char)Symbol::GROUND);
                if (pos == -1) {
                    break;
                }
                last += pos + 1;
            }
            x_ground_end = max(x_ground_end, (size_t)last);
        }
    }

    if (y_ground_start == SIZE_MAX) {
        throw exception("Level without ground");
    }

    CharMatrix matrix(x_ground_end - x_ground_start + 1, y_ground_end - y_ground_start + 1);
    for (size_t i = 0; i < matrix.size_y; i++) {
        for (size_t j = 0; j < matrix.size_x; j++) {
            matrix[i][j] = ' ';
        }
    }

    World* world = new World;

    for (size_t i = 0; i < text.size();i++) {
        string line = text[i];
        for (size_t j = 0; j < line.size(); j++) {
            char symbol = line[j];
            switch (symbol)
            {
            case (char)Symbol::GROUND:
                matrix[i - y_ground_start][j - x_ground_start] = (char)Symbol::GROUND;
                break;

            case (char)Symbol::HERO:
                world->AddObject(new Hero(j, i));
                break;

            case (char)Symbol::MUSROOM:
                world->AddObject(new Mushroom(j, i));
                break;

            default:
                break;
            }             
        }
    }
   
    Ground* ground = new Ground(x_ground_start, y_ground_start, matrix);
    world->AddObject(ground);

    return world;
}

std::vector<std::string> LevelLoader::ReadFile(std::string path)
{
    vector<string> text;
    string line;
    ifstream file(path);
    if (!file.is_open()) {
        throw exception("Bad level load");
    }

    for (int line_number = 0; getline(file, line); line_number++) {
        if (line == "---LEVEL END---") {
            break;
        }
        text.push_back(line);
    }

    file.close();
    return text;
}
