#pragma once
enum ButtonKey {
	a = 'A',
	d = 'D',
	SPACE = ' '
};

class InputReader
{
public:
	static bool IsButtonDown(int button);
};
