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

CharMatrix::CharMatrix(const std::vector<std::string>& strings):
    size_y(strings.size()),
    size_x(GetMaxSize(strings))
{
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

const std::vector<char>& CharMatrix::operator[](int index) const 
{
    return matrix[index];
}

int CharMatrix::GetMaxSize(const std::vector<std::string>& strings) const
{
    int max_x = 0;
    for (size_t i = 0; i < strings.size(); i++) {
        if ((int)strings[i].size() > max_x) {
            max_x = strings[i].size();
        }
    }
    return max_x;
}
