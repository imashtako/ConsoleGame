#pragma once

#include <time.h>

class MainCircle
{
public:
	MainCircle(int rate);
	void WaitNextFrame();

private:
	clock_t  previous_time;
	int frame_rate;
	clock_t time_between_frames;
};

