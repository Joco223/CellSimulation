#pragma once


class Particle {
public:
	int x, y;
	int type;

	Particle();
	Particle(int, int, int);
};

Particle::Particle() {
	type = 0;
}

Particle::Particle(int _x, int _y, int _type) {
	x = _x;
	y = _y;
	type = _type;
}