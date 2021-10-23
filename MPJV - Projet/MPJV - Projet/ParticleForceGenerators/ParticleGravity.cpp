#include "ParticleGravity.h"
#include <iostream>

void ParticleGravity::UpdateForce(Particle* particle, float deltaTime)
{
	particle->addForce(particle->getMass() * m_gravity);
}