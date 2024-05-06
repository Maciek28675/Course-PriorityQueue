#ifndef TIMER_HPP
#define TIMER_HPP

#include <chrono>
#include <iostream>

using namespace std::chrono;

class Timer
{

private:
	high_resolution_clock::time_point start_time, end_time;
	duration<double> duration;
};

#endif 