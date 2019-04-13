#pragma once

#include "allegro5/allegro_primitives.h"

class Player
{
public:
	Player();
	~Player();

	void update();
	void draw();

	ALLEGRO_COLOR color;

	float x;
	float y;
	float width;
	float height;
	float velX;
	float velY;
	float gravity;
};