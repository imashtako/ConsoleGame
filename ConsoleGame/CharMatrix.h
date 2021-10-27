#pragma once

#include <vector>
#include <string>

class CharMatrix
{
public:
	std::vector<std::vector<char>> matrix;
	const size_t size_x;
	const size_t size_y;
	CharMatrix(size_t x, size_t y);
	CharMatrix(const std::vector<std::string>& strings);
	std::vector<char>& operator[](int index);
	const std::vector<char>& operator[](int index) const;
private:
	int GetMaxSize(const std::vector<std::string>& strings) const;
};

