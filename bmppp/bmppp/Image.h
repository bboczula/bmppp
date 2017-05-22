#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <Windows.h>
#include <algorithm>

class Image
{
public:
	Image();
	~Image();
	void loadFromFile(std::string fileName);
	BYTE* getPixelData();
	DWORD getWidth();
	DWORD getHeight();
private:
	std::string fileName;
	WORD bitsPerPixel;
	DWORD pixelDataOffset;
	UINT numOfColorsInPalette;
	DWORD width;
	DWORD height;
	BYTE* pixelData;
private:
	void readHeaders();
	int calculatePadding(DWORD lineSize);
	void printInfo();
	void readPixelData();
};
