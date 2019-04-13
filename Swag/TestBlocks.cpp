#include "pch.h"
#include "TestBlocks.h"
#include "allegro5/allegro_primitives.h"

TestBlocks::TestBlocks()
{
}

TestBlocks::~TestBlocks()
{
}
void TestBlocks::update()
{

}
void TestBlocks::draw()
{
	ALLEGRO_COLOR colorRed = al_map_rgb(255, 0, 0);


	al_draw_filled_rectangle(0 ,0 ,64, 64, colorRed);


}




