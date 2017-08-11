#pragma once

#include <vector>
#include <amp.h>

#include "Cell.h"

using namespace concurrency;

namespace Step {

	vector<Cell> updateCells(vector<Cell> cells) {
		if (cells.size() > 0) {		
			int size = cells.size();
			array_view<Cell, 1> source(size, cells);

			parallel_for_each(
				source.extent,
				[=](index<1> idx) restrict(amp) {

				if (source[idx].state == true) {
					if (source[idx].currentHunger > 0) {
						source[idx].currentHunger -= 1;
						if (source[idx].currentSize < source[idx].divisionSize) {
							source[idx].currentSize += 1;
						}
					}

					if (source[idx].currentHunger <= 0) {
						source[idx].health -= 1;
					}

					if (source[idx].health <= 0) {
						source[idx].state = false;
					}
				}		

			});
		}
		return cells;
	}

}