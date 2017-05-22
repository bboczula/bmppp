#include <iostream>
#include <thread>

#include "Image.h"
#include "Timer.h"

int main()
{
	// Prepare timer
	Timer timer;

	// Run other stuff
	const int N = 20;
	Image* img[N];

	timer.start();
	for (int i = 0; i < N; i++)
	{
		img[i] = new Image;
		std::thread myFirst(&Image::loadFromFile, img[i], "C:\\Users\\Perf\\Desktop\\test_bmp.bmp");
		myFirst.join();
	}

	for (int i = 0; i < N; i++)
	{
		delete img[i];
	}

	getchar();
	timer.stop();
	getchar();
}