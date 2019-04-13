#include "pch.h"
#include "Player.h"
#include "allegro5/allegro_primitives.h"


player::player()
{

}

player::~player()
{

}

void player::update()
{
	x += .05;
	y += .05;
}

void player::draw()
{
	//(x1,y1,x2,y2,color)
	//ALLEGRO_COLOR color_orange = al_map_rgb(255, 210, 0);
	//al_draw_rectangle(1,1,10,10, color_orange, 1);
	al_draw_filled_rectangle(x, y, x+64, y+64, al_map_rgb(255, 0, 0));

}