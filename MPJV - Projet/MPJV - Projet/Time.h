#pragma once

#include <chrono>
#include "System.h"

class Time : public System
{
public:
	Time()
	{
		deltaTime = 0.01f;
		time = 0.0f;
		currentTime = clock();
		accumulator = 0.0f;
		alpha = 0;
	}
	float deltaTime;
	float time;
	float alpha;
	void tick(std::vector<Entity*> entities) override
	{
		//printf("time tick");
		float newTime = clock();
		float frameTime = (newTime - currentTime) / CLOCKS_PER_SEC;
		if (frameTime > 0.25)
			frameTime = 0.25;
		currentTime = newTime;

		accumulator += frameTime;

		while (accumulator >= deltaTime)
		{
			//Update physics
			//physic.update(time, deltaTime);
			time += deltaTime;
			accumulator -= deltaTime;
		}

		const float alpha = accumulator / deltaTime;
	}

private:
	float currentTime;
	float accumulator;
};
