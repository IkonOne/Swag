#include "pch.h"
#include "Blocks.h"
#include "allegro5/allegro_primitives.h"

Blocks::Blocks()
{
}


Blocks::~Blocks()
{

}

void Blocks::update()
{

}
void Blocks::draw()
{
	ALLEGRO_COLOR colorRed = al_map_rgb(255, 0, 0);
	al_draw_filled_rectangle(0, 0, 64, 64, colorRed);
	


}
