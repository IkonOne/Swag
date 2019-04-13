#pragma once

#include "State.h"
#include "BulletMgr.h"

class TestBullet :
	public State
{
public:
	TestBullet();
	~TestBullet();

	BulletMgr bulletMgr;

	virtual void update();
	virtual void draw();
};

