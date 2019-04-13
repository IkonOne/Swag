#pragma once
#include "State.h"
class TestTilemap :
	public State
{
public:
	TestTilemap();
	~TestTilemap();
	void setTile();
	void getTile();
	void draw();
};


