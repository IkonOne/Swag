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
	TileMap map;

	map.setTile(0,9);
	map.draw();
}

void TestTilemap::getTile()
{

}

void TestTilemap::setTile()
{

}
