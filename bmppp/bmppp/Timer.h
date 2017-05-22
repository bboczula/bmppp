#pragma once

#include <Windows.h>
#include <iostream>

class Timer
{
public:
	Timer();
	~Timer();
	void start();
	void stop();
private:
	LARGE_INTEGER secondsPerCount;
	LARGE_INTEGER startingTime;
	LARGE_INTEGER endingTime;
	LARGE_INTEGER elapsedMicroseconds;
	LARGE_INTEGER frequency;
};
