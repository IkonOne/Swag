#pragma once
class TileMap
{
public:
	TileMap();
	~TileMap();
	bool getTile(int x, int y);
	void setTile(int x, int y);
	void draw();
};

