#include "CharMatrix.h"

#include <string>

using namespace std;

CharMatrix::CharMatrix(size_t x, size_t y): size_x(x), size_y(y)
{
	matrix = vector<vector<char>>(y);
    for (size_t i = 0; i < size_y; i++) {
        matrix[i] = vector<char>(x);
    }
}

CharMatrix::CharMatrix(const std::vector<std::string>& strings)
{
    size_y = strings.size();
    size_x = 0;
    for (size_t i = 0; i < size_y; i++) {
        if (strings[i].size() > size_x) {
            size_x = strings[i].size();
        }
    }

    matrix = vector<vector<char>>(size_y);
    for (size_t i = 0; i < size_y; i++) {
        matrix[i] = vector<char>(size_x);
    }

    for (size_t i = 0; i < size_y; i++) {
        for (size_t j = 0; j < size_x; j++)
        {
            matrix[i][j] = strings[i][j];
        }
    }
}

std::vector<char>& CharMatrix::operator[](int index)
{
    return matrix[index];
}
