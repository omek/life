#include <iostream>
#include <time.h>
#include <Windows.h>
#include "life.h"


int main()
{
	int height = 40;
	int width = 80;
	HANDLE handle = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	DWORD test;
	std::vector<std::vector<bool>> temp_vec;
	SetConsoleActiveScreenBuffer(handle);
	wchar_t*buffer = new wchar_t[width * height];
	srand(time(NULL));

	life newLife(height, width);
	newLife.randomize(10);

	while (true) {
		for (int i = 0; i < width*height; i++)
			buffer[i] = ' ';
		temp_vec = newLife.step();
		for (int i = 0; i < temp_vec.size(); i++) {
			for (int j = 0; j < temp_vec[i].size(); j++)
				if (temp_vec[i][j]) {
					buffer[i + j * width] = 0x25A0;
				}
		}
		WriteConsoleOutputCharacter(handle, buffer, width * height, { 0,0 }, &test);
		Sleep(60);
	}
	return 0;
}

