#pragma once

#include <vector>
#include <algorithm>

#include "Particle.h"
#include "ParticleStructure.h"
#include "ParticleEmitter.h"
#include "pSpiralEmitter.h"

class ParticleSystem {
public:
	vector<ParticleEmitter> emitters;

	void createEmitter(int x, int y, pSpiralEmitter type, int lifeTime) {
		ParticleEmitter PE(x, y, type, lifeTime);
		emitters.push_back(PE);
	}

	ParticleSystem();
};

ParticleSystem::ParticleSystem() {};