#include "Timer.h"

Timer::Timer()
{
	QueryPerformanceFrequency(&frequency);
}

Timer::~Timer()
{
}

void Timer::start()
{
	QueryPerformanceCounter(&startingTime);
}

void Timer::stop()
{
	QueryPerformanceCounter(&endingTime);
	elapsedMicroseconds.QuadPart = endingTime.QuadPart - startingTime.QuadPart;
	elapsedMicroseconds.QuadPart *= 1000;
	elapsedMicroseconds.QuadPart /= frequency.QuadPart;

	std::cout << "Time: " << elapsedMicroseconds.QuadPart << " ms " << std::endl;
}