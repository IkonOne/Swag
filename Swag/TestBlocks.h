#pragma once
#include "State.h"
class TestBlocks:
	public State
{
public:
	TestBlocks();
	~TestBlocks();
	float x;
	float y;
	float width;
	float height;
	float velX;
	float velY;
	virtual void update();
	virtual void draw();
};
