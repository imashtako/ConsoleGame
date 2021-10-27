#pragma once

#include <time.h>

class MainCircle
{
public:
	MainCircle(float rate);
	void WaitNextFrame();

private:
	clock_t  previous_time;
	float frame_rate;
	clock_t time_between_frames;
};

