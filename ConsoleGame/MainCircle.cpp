#include "MainCircle.h"

MainCircle::MainCircle(float rate): previous_time(clock()), frame_rate(rate) {
    time_between_frames = 1000.0 / rate;
}
void MainCircle::WaitNextFrame()
{
    while (clock() - previous_time < time_between_frames) {}
    previous_time = clock();
}
;
