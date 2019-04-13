#pragma once
#include "State.h"
class player :
	public State
{
public:
	player();

	virtual void update();
	virtual void draw();

	float x = 0;
	float y = 0;
	float width;
	float height;
	float velX;
	float velY;
};