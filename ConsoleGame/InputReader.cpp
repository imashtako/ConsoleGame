#include "InputReader.h"

#include <Windows.h>

using namespace std;

bool InputReader::IsButtonDown(int button)
{
    return GetKeyState(button)&0x80;
}
