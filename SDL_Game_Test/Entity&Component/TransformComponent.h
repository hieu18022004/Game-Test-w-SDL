#pragma once
#include "Components.h"
#include "../Vector2D.h"

class TransformComponent : public Component
{

public:
	Vector2D position;

	TransformComponent()
	{
		position.x = 0.0f;
		position.y = 0.0f;
	}

	void init() override
	{
		position.x = 0.0f;
		position.y = 0.0f;
	}

	TransformComponent(float xpos, float ypos)
	{
		position.x = xpos;
		position.y = ypos;
	}

	void update() override
	{
	
	}
};