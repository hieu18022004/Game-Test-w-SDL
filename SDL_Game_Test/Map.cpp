#include "Map.h"
#include "TextureManage.h"
#include "Game.h"
#include "Entity&Component/Entity&Component.h"
#include "Entity&Component/Components.h"
#include <fstream>

extern Manager manager;

Map::Map(const char* mapFile, int mapScale, int tileSize) : mapFile(mapFile), mapScale(mapScale), tileSize(tileSize)
{
	scaleSize = tileSize * mapScale;
}

Map::~Map() 
{
}

void Map::mapLoad(string path, int sizeX, int sizeY)
{
	char tile;
	fstream mapFile;
	mapFile.open(path);

	int srcX, srcY;

	for (int y = 0; y < sizeY; y++)
	{
		for (int x = 0; x < sizeX; x++)
		{
			mapFile.get(tile);
			srcY = atoi(&tile) * tileSize;
			mapFile.get(tile);
			srcX = atoi(&tile) * tileSize;
			addTile(srcX, srcY, x * tileSize * mapScale, y * tileSize * mapScale);
			mapFile.ignore();
		}
	}
	mapFile.ignore();
	for (int y = 0; y < sizeY; y++)
	{
		for (int x = 0; x < sizeX; x++)
		{
			mapFile.get(tile);
			if (tile == '1')
			{
				auto& tcol(manager.addEntity());
				tcol.addComponent<Collider>("terrain", x * scaleSize, y * scaleSize, scaleSize);
				tcol.addGroup(Game::groupColliders);
			}
			mapFile.ignore();
		}
	}

	mapFile.close();
}

void Map::addTile(int srcX, int srcY, int x, int y)
{
	auto& tile(manager.addEntity());
	tile.addComponent<TileComponent>(srcX, srcY, x, y, tileSize, mapScale, mapFile);
	tile.addGroup(Game::groupMap);
}

