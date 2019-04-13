#include "pch.h"
#include "TestTilemap.h"
#include "TileMap.h"
#include "allegro5/allegro_primitives.h"

TestTilemap::TestTilemap()
{
}

TestTilemap::~TestTilemap()
{

}

void TestTilemap::draw()
{
	al_draw_filled_rectangle(50, 50, 50, 50, al_map_rgb(0, 255, 0));
}

void TestTilemap::getTile()
{

}

void TestTilemap::setTile()
{

}
