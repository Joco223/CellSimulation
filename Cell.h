#pragma once

#include <vector>

using namespace std;

class Cell {
public:
	//Base
	int x, y;
	int sizeX, sizeY;
	int c[3];
	bool state;

	//Traits
	int health;
	int maxHealth;
	int imunity;
	int speed;
	int stenght;
	int viewRange;
	int pickupRange;
	int foodEff;
	int currentSize;
	int divisionSize;
	int currentHunger;
	//vector<int> acceptedFood;

	//Brain

	Cell();
};

Cell::Cell() {};