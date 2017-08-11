#pragma once

#include <vector>
#include <algorithm>

#include "Particle.h"

using namespace std;

class ParticleStructure {
public:
	int size;
	vector<Particle> particles;

	ParticleStructure();
	ParticleStructure(int);

	int checkNeighbours(int x, int y, int cX, int cY, int size) {
		//X bounds
		int boundXP = size;
		int boundXM = 0;
		//Y bounds
		int boundYP = size;
		int boundYM = 0;

		int nAmount = 0;

		if (x == boundXP) {
			if (particles[(y - 1) * size + (x - 1)].type != 0) { nAmount++; }
			if (particles[(y - 1) * size + (x    )].type != 0) { nAmount++; }
			if (particles[(y    ) * size + (x - 1)].type != 0) { nAmount++; }
			if (particles[(y + 1) * size + (x - 1)].type != 0) { nAmount++; }
			if (particles[(y + 1) * size + (x    )].type != 0) { nAmount++; }
		}
		else if (x == boundXM) {
			if (particles[(y - 1) * size + (x    )].type != 0) { nAmount++; }
			if (particles[(y - 1) * size + (x + 1)].type != 0) { nAmount++; }
			if (particles[(y    ) * size + (x + 1)].type != 0) { nAmount++; }
			if (particles[(y + 1) * size + (x    )].type != 0) { nAmount++; }
			if (particles[(y + 1) * size + (x + 1)].type != 0) { nAmount++; }
		}
		else if (y == boundYP) {
			if (particles[(y - 1) * size + (x - 1)].type != 0) { nAmount++; }
			if (particles[(y - 1) * size + (x    )].type != 0) { nAmount++; }
			if (particles[(y - 1) * size + (x + 1)].type != 0) { nAmount++; }
			if (particles[(y    ) * size + (x - 1)].type != 0) { nAmount++; }
			if (particles[(y    ) * size + (x + 1)].type != 0) { nAmount++; }
		}
		else if (y == boundYM) {
			if (particles[(y    ) * size + (x - 1)].type != 0) { nAmount++; }
			if (particles[(y    ) * size + (x + 1)].type != 0) { nAmount++; }
			if (particles[(y + 1) * size + (x - 1)].type != 0) { nAmount++; }
			if (particles[(y + 1) * size + (x    )].type != 0) { nAmount++; }
			if (particles[(y + 1) * size + (x + 1)].type != 0) { nAmount++; }
		}
		else if (x == boundXP && y == boundYP) {
			if (particles[(y - 1) * size + (x - 1)].type != 0) { nAmount++; }
			if (particles[(y - 1) * size + (x    )].type != 0) { nAmount++; }
			if (particles[(y    ) * size + (x - 1)].type != 0) { nAmount++; }
		}
		else if (x == boundXM && y == boundYP) {
			if (particles[(y - 1) * size + (x    )].type != 0) { nAmount++; }
			if (particles[(y - 1) * size + (x + 1)].type != 0) { nAmount++; }
			if (particles[(y    )* size + (x + 1)].type != 0) { nAmount++; }
		}
		else if (x == boundXP && y == boundYM) {
			if (particles[(y    ) * size + (x - 1)].type != 0) { nAmount++; }
			if (particles[(y + 1) * size + (x - 1)].type != 0) { nAmount++; }
			if (particles[(y + 1) * size + (x    )].type != 0) { nAmount++; }
		}
		else if (x == boundXM && y == boundYM) {
			if (particles[(y    ) * size + (x + 1)].type != 0) { nAmount++; }
			if (particles[(y + 1) * size + (x    )].type != 0) { nAmount++; }
			if (particles[(y + 1) * size + (x + 1)].type != 0) { nAmount++; }
		}
		else {
			if (particles[(y - 1) * size + (x - 1)].type != 0) { nAmount++; }
			if (particles[(y - 1) * size + (x    )].type != 0) { nAmount++; }
			if (particles[(y - 1) * size + (x + 1)].type != 0) { nAmount++; }
			if (particles[(y    ) * size + (x - 1)].type != 0) { nAmount++; }
			if (particles[(y    ) * size + (x + 1)].type != 0) { nAmount++; }
			if (particles[(y + 1) * size + (x - 1)].type != 0) { nAmount++; }
			if (particles[(y + 1) * size + (x    )].type != 0) { nAmount++; }
			if (particles[(y + 1) * size + (x + 1)].type != 0) { nAmount++; }
		}
		return nAmount;
	}

	void createParticleStructure(int size, int x, int y) {
		int area = size * size;
		particles.resize(area);
		int seed = 0;
		int curX = (size / 2);
		int curY = (size / 2);
		int type = 1;

		particles[curY * size + curX].type = type;
		particles[curY * size + curX].x = curX;
		particles[curY * size + curX].y = curY;

		for (int i = 0; i < size; i++) {
			//srand(seed);
			curY++;
			//int nAmount = 0;

			for (int j = 0; j < ((i - 1) / 2); j++) {
				curX++;
				//int chance = rand() % 100;
				//seed = chance;
				//if (chance < 20) {
					if (checkNeighbours(curX, curY, x, y, size) > 0) {
						particles[curY * size + curX].type = type;
						particles[curY * size + curX].x = curX;
						particles[curY * size + curX].y = curY;
					}			
				//}
			}

			for (int j = 0; j < i - 1; j++) {
				curY++;
				//int chance = rand() % 100;
				//seed = chance;
				//if (chance < 20) {
					if (checkNeighbours(curX, curY, x, y, size) > 0) {
						particles[curY * size + curX].type = type;
						particles[curY * size + curX].x = curX;
						particles[curY * size + curX].y = curY;
					}
				//}
			}

			for (int j = 0; j < i - 1; j++) {
				curX--;
				//int chance = rand() % 100;
				//seed = chance;
				//if (chance < 20) {
					if (checkNeighbours(curX, curY, x, y, size) > 0) {
						particles[curY * size + curX].type = type;
						particles[curY * size + curX].x = curX;
						particles[curY * size + curX].y = curY;
					}
				//}
			}

			for (int j = 0; j < i - 1; j++) {
				curY--;
				//int chance = rand() % 100;
				//seed = chance;
				//if (chance < 20) {
					if (checkNeighbours(curX, curY, x, y, size) > 0) {
						particles[curY * size + curX].type = type;
						particles[curY * size + curX].x = curX;
						particles[curY * size + curX].y = curY;
					}
				//}
			}

			for (int j = 0; j < i - ((i / 2) + 2); j++) {
				curY++;
				//int chance = rand() % 100;
				//seed = chance;
				//if (chance < 20) {
					if (checkNeighbours(curX, curY, x, y, size) > 0) {
						particles[curY * size + curX].type = type;
						particles[curY * size + curX].x = curX;
						particles[curY * size + curX].y = curY;
					}
				//}
			}
		}
	}
};

ParticleStructure::ParticleStructure() {};

ParticleStructure::ParticleStructure(int _size) {
	size = _size;
}
