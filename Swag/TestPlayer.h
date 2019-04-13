#pragma once
#include "State.h"
class TestPlayer :
	public State
{
public:
	TestPlayer();
	~TestPlayer();

	virtual void update();
	virtual void draw();

	float x=0;
	float y=0;
	float width;
	float height;
	float velX;
	float velY;
};