#pragma once
#include "State.h"
class player
{
public:
	player();
	~player();

	virtual void update();
	virtual void draw();

	float x;
	float y;
	float width;
	float height;
	float velX=.1;
	float velY=0;
	float gravity = .01;
};