#include "pch.h"
#include "TileMap.h"
#include "allegro5/allegro_primitives.h"

TileMap::TileMap()
{
}


TileMap::~TileMap()
{
}

void TileMap::draw()
{
	al_draw_filled_rectangle(0, 1, 1, 1, al_map_rgb(0, 255, 0));
}

void TileMap::getTile()
{

}

void TileMap::setTile()
{

}
