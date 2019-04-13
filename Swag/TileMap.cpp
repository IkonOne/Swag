#include "pch.h"
#include "TileMap.h"
#include "allegro5/allegro_primitives.h"
#include <iostream>

TileMap::TileMap()
{
}


TileMap::~TileMap()
{
}

void TileMap::draw()
{
	int x = 0;
	int y = 0;
	int columns = 20;
	int rows =11;

	for (int i = 0; i < rows; i++)
	{
		x = 0;
		for (int i = 0; i < columns; i++)
		{
			al_draw_filled_rectangle(x, y, x + 64, y + 64, al_map_rgb(255, 0, 0));
			x = x + 64;
		}
		y = y + 64;
	}
}

void TileMap::getTile()
{

}

void TileMap::setTile()
{

}
