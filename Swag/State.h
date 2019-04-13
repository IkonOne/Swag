#pragma once

#include "allegro5/allegro.h"

class State
{
public:
	State();
	~State();

	virtual void update();
	virtual void draw();
	virtual void handleEvents(ALLEGRO_EVENT *event);
};

