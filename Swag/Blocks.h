#pragma once
class Blocks
{
public:
	Blocks();
	~Blocks();
	
	float x;
	float y;
	float width;
	float height;
	float velX;
	float velY;
	
	virtual void update();
	virtual void draw();
};

