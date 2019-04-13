#include "pch.h"

#include "allegro5/allegro_primitives.h"
#include "common.h"
#include "TestBullet.h"

float x = 0;

TestBullet::TestBullet()
{
	bulletMgr.addBullet(0, 0, 5, 0, 10);
}


TestBullet::~TestBullet()
{
}


void TestBullet::update()
{
	bulletMgr.update();
}

void TestBullet::draw()
{
	bulletMgr.draw();
}