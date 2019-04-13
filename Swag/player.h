#pragma once
class Player
{
public:
	Player();
	~Player();

	void update();
	void draw();

	float x;
	float y;
	float width;
	float height;
	float velX;
	float velY;
	float gravity;
};