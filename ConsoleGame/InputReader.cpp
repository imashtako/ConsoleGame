#include "InputReader.h"

#include <conio.h>

using namespace std;

bool InputReader::IsButtonDown(int button) const
{
    return buttons.count(button) > 0;
}

void InputReader::CleanBuffer()
{
    buttons.clear();
}

void InputReader::Start()
{
    if (is_work) { return; }
    is_work = true;
    read_future = async([this]() {this->Read();});
}

void InputReader::Stop()
{
    if (!is_work) { return; }
    is_work = false;
    read_future.wait();
}

void InputReader::Read()
{
    while (is_work) {
        buttons.insert(_getch());
    }
}
