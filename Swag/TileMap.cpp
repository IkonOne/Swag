#include "pch.h"
#include "TileMap.h"
#include "allegro5/allegro_primitives.h"

bool activeTile[20][11];

int x = 0;
int y = 0;
int columns = 20;
int rows = 11;

TileMap::TileMap()
{
}


TileMap::~TileMap()
{
}

void TileMap::draw()
{
	for (int i = 0; i < 20; i++)
	{
		activeTile[i][10] = true;
	}

	for (int i = 0; i < columns; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			if (activeTile[i][j])
			{
				al_draw_rectangle(64 * i, 64 * j, (64 * i) + 64, (64 * j) + 64, al_map_rgb(255, 0, 0), 2);
			}
		}
	}
}

bool TileMap::getTile(int x, int y)
{
	return activeTile[x][y];
}

void TileMap::setTile(int x, int y)
{
	activeTile[x][y] = true;
}
