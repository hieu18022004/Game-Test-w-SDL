#pragma once
#include <SDL.h>

class Collider;

class Collision
{
public:
	static bool isCollide(const SDL_Rect& rectA, const SDL_Rect& rectB, char& direction);
	static bool isCollide(const Collider& colA, const Collider& colB, char& direction);
};