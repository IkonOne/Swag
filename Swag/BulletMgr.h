#pragma once

#include <list>
#include <memory>

struct bullet_s {
	float x;
	float y;
	float velX;
	float velY;
	float gravity;
};

class BulletMgr
{
public:
	BulletMgr();
	~BulletMgr();

	std::list< std::shared_ptr<bullet_s> > bullets;

	void update();
	void draw();
	void addBullet(float x, float y, float velX, float velY, float gravity);
	void removeBullet(std::shared_ptr<bullet_s> bullet);
};

