#include "pch.h"
#include "TestBlocks.h"
#include "allegro5/allegro_primitives.h"
#include "Blocks.h"


#define blockGrav 10;
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
	
	Blocks blocks;
	blocks.draw();


}
void randomBlocks()
{

}




