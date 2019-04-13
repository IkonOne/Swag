#pragma once

#include "State.h"
#include "allegro5/allegro.h"

class GameState :
	public State
{
public:
	GameState();
	~GameState();

	virtual void update();
	virtual void draw();
	virtual void handleEvents(ALLEGRO_EVENT * event);
};

