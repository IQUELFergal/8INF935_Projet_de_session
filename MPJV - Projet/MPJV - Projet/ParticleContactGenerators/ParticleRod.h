#pragma once
#include "ParticleLink.h"

class ParticleRod : public ParticleLink
{
	// A contact will be generated if the distance
	//between particles is not equal to the length
	float m_length;

	unsigned int addContact(std::vector<ParticleContact*>* contact, unsigned int limit) const;
};