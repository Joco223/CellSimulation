#pragma once

#include <vector>

#include "Particle.h"
#include "ParticleSystem.h"
#include "pSpiralEmitter.h"

class ParticleEmitter {
public:
	int x, y;
	pSpiralEmitter type;
	int lifeTime;

	ParticleEmitter();
	ParticleEmitter(int, int, pSpiralEmitter, int);
};

ParticleEmitter::ParticleEmitter() {};

ParticleEmitter::ParticleEmitter(int _x, int _y, pSpiralEmitter _type, int _lifeTime) {
	x = _x;
	y = _y;
	type = _type;
	lifeTime = _lifeTime;
}