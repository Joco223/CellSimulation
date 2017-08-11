#pragma once

#include <SDL.h>
#include <vector>

#include "Cell.h"

namespace Graphics {

	Uint32* drawPixel(int x, int y, int c[], SDL_Surface *pixelSurface, int width) {
		Uint32 * pixels = (Uint32 *)pixelSurface->pixels;
		pixels[y * width + x] = SDL_MapRGB(pixelSurface->format, c[2], c[1], c[0]);
		return pixels;
	}

	Uint32* drawSquare(int posX, int posY, int c[], int scale, SDL_Surface *pixelSurface, int width) {
		Uint32 * pixels = (Uint32 *)pixelSurface->pixels;
		for (int i = 0; i < scale; i++) {
			for (int j = 0; j < scale; j++) {
				drawPixel(posX + j, posY + i, c, pixelSurface, width);
			}
		}
		return pixels;
	}

	void drawBackround(int width, int height, int c[], SDL_Surface *pixelSpace) {
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				drawPixel(j, i, c, pixelSpace, width);
			}
		}
	}

	void drawCells(vector<Cell> cells, SDL_Surface *pixelSpace, int width) {
		for (int i = 0; i < cells.size(); i++) {
			drawPixel(cells[i].x, cells[i].y, cells[i].c, pixelSpace, width);
		}
	}

}