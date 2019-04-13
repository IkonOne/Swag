#include "pch.h"

#include <memory>
#include <list>

#include "allegro5/allegro_primitives.h"

#include "common.h"
#include "BulletMgr.h"

BulletMgr::BulletMgr()
{
	bullets = { };
}


BulletMgr::~BulletMgr()
{
}

void BulletMgr::update()
{
	for (std::shared_ptr<bullet_s> b : bullets) {
		b->velY += b->gravity * DT;

		b->x += b->velX * DT;
		b->y += b->velY * DT;
	}
}

void BulletMgr::draw()
{
	for (std::shared_ptr<bullet_s> b : bullets) {
		al_draw_line(b->x, b->y, b->x + b->velX, b->y + b->velY, al_map_rgb(255, 0, 0), 2);
	}
}

void BulletMgr::addBullet(float x, float y, float velX, float velY, float gravity)
{
	std::shared_ptr<bullet_s> bullet = std::make_shared<bullet_s>();
	
	bullet->x = x;
	bullet->y = y;
	bullet->velX = velX;
	bullet->velY = velY;
	bullet->gravity = gravity;

	bullets.push_back(bullet);
}

void BulletMgr::removeBullet(std::shared_ptr<bullet_s> bullet) {
	bullets.remove(bullet);
}
