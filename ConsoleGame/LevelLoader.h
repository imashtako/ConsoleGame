#pragma once
#include <string>
#include <vector>

#include "World.h"

class LevelLoader
{
public:
	World* LoadLevel(std::string path);

private:
	std::vector<std::string> ReadFile(std::string path);
};

