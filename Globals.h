#pragma once

namespace Globals
{
	extern unsigned int gametime;
	extern const unsigned int screenWidth;
	extern const unsigned int screenHeight;
	extern const unsigned int FPS;
	extern const unsigned int tileDimension;
	extern void Update();
}

int GetGameTime();
int GetGameScreenWidth();
int GetGameScreenHeight();
int GetGameFPS();
int GetTileDimension();
bool GameTimeSecondsPassed(const int seconds);
