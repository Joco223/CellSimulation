// FLEXO 1
// FLEXO 2
// FLEXO 3
//Standard libraries
#include <SDL.h>
#include <stdio.h>
#include <amp.h>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iostream>
#include <time.h> 

//Custom libraries
#include "Cell.h"
#include "Graphics.h"
#include "Step.h"

//SDL Stuff
SDL_Window* window;
SDL_Surface* surface;
SDL_Surface* pixelSpace;
SDL_Renderer* renderer;
SDL_Texture* texture;

Uint32* pixels;

//Globals
const int width = 640;
const int height = 480;

//Namespaces
using namespace concurrency;
using namespace std;

//Other stuff
vector<Cell> cells;

int tick = 0;
int maxTick = 100;

//Colors
int black[3] = {   0,   0,   0 };
int   red[3] = { 255,   0,   0 };
int  blue[3] = {   0,   0, 255 };
int green[3] = {   0, 255,   0 };

int Init() {
	window = NULL;
	surface = NULL;
	renderer = NULL;
	texture = NULL;
	pixelSpace = NULL;

	window = SDL_CreateWindow("Cell Simulation", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
	surface = SDL_GetWindowSurface(window);
	pixelSpace = SDL_CreateRGBSurface(0, width, height, 32, 0x000000ff, 0x0000ff00, 0x00ff0000, 0xff000000);
	pixels = (Uint32 *)pixelSpace->pixels;
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STATIC, width, height);

	return 0;
}

void cleanUp() {
	SDL_DestroyTexture(texture);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void Draw() {
	Graphics::drawBackround(width, height, black, pixelSpace);
	Graphics::drawCells(cells, pixelSpace, width);
}

void updateCells() {
	if (tick >= maxTick) {
		cells = Step::updateCells(cells);
		tick = 0;

		cout << "Hunger: " << cells[0].currentHunger << endl;
		cout << "Size: " << cells[0].currentSize << endl;
		cout << "Health:" << cells[0].health << endl;
		cout << "Status: " << cells[0].state << endl;
		cout << endl;
	}
	tick++;
}

void updateScreen() {
	updateCells();
	Draw();
	
	SDL_UpdateTexture(texture, NULL, pixelSpace->pixels, pixelSpace->pitch);
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, texture, NULL, NULL);
	SDL_RenderPresent(renderer);
}

int main(int argc, char *argv[]) {	
	bool quit = false;

	SDL_Event event;

	Init();

	Cell test;
	test.x = 100;
	test.y = 100;
	test.c[3] = *red;
	test.health = 20;
	test.maxHealth = 20;
	test.currentHunger = 50;
	test.currentSize = 1;
	test.divisionSize = 20;
	test.state = true;

	cells.push_back(test);

	while (!quit) {
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_QUIT:
				quit = true;
				break;
			}
		}
		updateScreen();
	}
	cleanUp();
	return 0;
}
