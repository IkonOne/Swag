#pragma once

#include "allegro5/allegro.h"
#include "allegro5/allegro_primitives.h"

#define DT		1.0/60.0

#define GAME_WIDTH		1280
#define GAME_HEIGHT		720

const ALLEGRO_COLOR COLOR_RED = al_map_rgb(255, 0, 0);
const ALLEGRO_COLOR COLOR_GREEN = al_map_rgb(0, 255, 0);
const ALLEGRO_COLOR COLOR_BLUE = al_map_rgb(0, 0, 255);


static bool checkOvLp(double left1, double right1, double top1, double bot1,
	double left2, double right2, double top2, double bot2)
{
	if (right1 < left2 ||
		left1 > right2 ||
		top1 > bot2 ||
		bot1 < top2)
	{
		return false;

	}
	else {
		return true;
	}
}



