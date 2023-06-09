#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "glad/include/glad/glad.h"
#include <iostream>
#include <vector>

/*
#include "lua/include/lua.h"
#include "lua/include/lauxlib.h"
#include "lua/include/lualib.h"

#pragma comment (lib, "lua/liblua54.a")
*/

#define ground 320
using namespace std;

const int WIDTH = 640;
const int HEIGHT = 480;

class Collider;
class AssetManager;

class Game
{
private:

	SDL_Window* window;

public:
	static SDL_Rect camera;
	static AssetManager* assets;

	static bool isRunning;
	Game();
	~Game();
	void init(const char* title, int xpos, int ypos, int width, int height);

	void handleEvent();
	void update();
	void render();
	void clean();
	bool running();


	static SDL_Renderer* renderer;
	static SDL_Event event;

	enum groupLabel : size_t
	{
		groupMapAbove,
		groupPlayers,
		groupColliders,
		groupActivateUp,
		groupActivateDown,
		groupActivateCheck,
		groupProjectile,
		groupMapBelow
	};


};

