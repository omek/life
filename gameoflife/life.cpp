#include "life.h"

life::life(int w, int h) :oldGrid(h, std::vector<bool>(w)), newGrid(h, std::vector<bool>(w)), Height(h), Width(w) {  }

void life::randomize(int probability) {
	for (int i = 0; i < Height; i++) {
		for (int j = 0; j < Width; j++) {
			if(i < Height -1 && j < Width -1)
				oldGrid[i][j] = (rand() % 100 <= probability);
		}
	}
	newGrid = oldGrid;
}


std::vector<std::vector<bool>> life::step() {
	oldGrid.swap(newGrid);
	for (int i = 0; i < oldGrid.size() - 1; i++) {
		for (int j = 0; j < oldGrid[i].size() - 1; j++) {
			int aliveCount = 0;

			if (j > 0 && i > 0) {
				for (int z = -1; z <= 1; z++) {
					for (int f = -1; f <= 1; f++)
						aliveCount += oldGrid[i + z][j + f];
				}
			}
			aliveCount -= oldGrid[i][j];

			if (oldGrid[i][j] && aliveCount < 2)
				newGrid[i][j] = false;
			else if (oldGrid[i][j] && aliveCount > 3)
				newGrid[i][j] = false;
			else if (!oldGrid[i][j] && aliveCount == 3)
				newGrid[i][j] = true;
			else
				newGrid[i][j] = oldGrid[i][j];
		}
	}
	
	return(oldGrid);
}

