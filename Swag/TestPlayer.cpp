#include "pch.h"
#include "TestPlayer.h"
#include "allegro5/allegro_primitives.h"
#include "player.h"

player player1;

TestPlayer::TestPlayer()
{
}

TestPlayer::~TestPlayer()
{
}

void TestPlayer::update()
{
	player1.update();
}

void TestPlayer::draw()
{
	player1.draw();
}