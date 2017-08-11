#pragma once


class Vector2D {
public:
	int x, y;

	bool checkBounds(int xP, int xM, int yP, int yM) {
		bool state = false;
		if (x <= xP && x >= xM) { state = true; }
		if (y <= yP && y >= yM) { state = true; }
	}
};