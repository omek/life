#pragma once
#include <vector>
class life
{
public:
	life(int w, int h);
	void randomize(int prawdopodobienstwo);
	std::vector<std::vector<bool>> step();
	~life();
private:
	int p;
	int Height;
	int Width;
	std::vector <std::vector<bool>> oldGrid;
	std::vector <std::vector<bool>> newGrid;
};

