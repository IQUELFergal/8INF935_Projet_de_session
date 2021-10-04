#include "Physics.h"

#pragma region Constructors
Physics::Physics()
{
}

#pragma endregion

#pragma region Mutex

void Physics::addParticle(float invertedMass, float damping, Vector3D position, Vector3D velocity, Vector3D acceleration)
{
    currentState.m_particles.push_back(Particle(invertedMass, damping, position, velocity, acceleration));
}

void Physics::addParticle(Particle particle)
{
    currentState.m_particles.push_back(particle);
}

void Physics::removeParticle(int index)
{
    currentState.m_particles.erase(currentState.m_particles.begin() + index);
}

#pragma endregion

#pragma region Accessors

Particle* Physics::getParticle(int id)
{
    return &currentState.m_particles[id];
}

std::vector<Particle>* Physics::getAllParticle()
{
    return &currentState.m_particles;
}

#pragma endregion

#pragma region Methods

void Physics::update(float t, float dt)
{
    previousState = currentState;
    //currentState.m_particleForceRegistry.updateForce(deltaTime);
    for (std::vector<Particle>::iterator it = currentState.m_particles.begin(); it != currentState.m_particles.end(); ++it) {
        it->integrate(dt);
    }
}

std::vector<Particle>* Physics::getIntermediateParticle(const float alpha)
{
    std::vector<Particle>* intermediateParticles = new std::vector<Particle>;
    for (int i = 0; i < previousState.m_particles.size(); i++) {
        intermediateParticles->push_back(Particle(currentState.m_particles[i].getPosition() * alpha + previousState.m_particles[i].getPosition() * (1-alpha)));
    }
    return intermediateParticles;
}

#pragma endregion