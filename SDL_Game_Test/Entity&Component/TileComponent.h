#pragma once
#include "Entity&Component.h"
#include "TransformComponent.h"
#include "SDL.h"
#include "SpriteComponent.h"

class TileComponent : public Component
{
public:
	TransformComponent* transform;
	SpriteComponent* sprite;

	SDL_Rect tileRect;
	int tileID;
	const char* path;

	TileComponent() = default;

	TileComponent(int x, int y, int w, int h, int id)
	{
		tileRect.x = x;
		tileRect.y = y;
		tileRect.w = w;
		tileRect.h = h;
		tileID = id;

		switch (tileID)
		{
		case 0:
		{
			path = "resource/dirt.png";
			break;
		}
		case 2:
		{
			path = "resource/water.png";
			break;
		}
		case 1:
		{
			path = "resource/grass.png";
			break;
		}
		}
	}

	void init() override
	{
		entity->addComponent<TransformComponent>((float)tileRect.x, (float)tileRect.y, tileRect.w, tileRect.h, 1);
		transform = &entity->getComponent<TransformComponent>();

		entity->addComponent<SpriteComponent>(path);
		sprite = &entity->getComponent<SpriteComponent>();
	}
};
