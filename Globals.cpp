#include "Globals.h"

namespace Globals
{
	unsigned int gametime = 0;
	const unsigned int screenWidth = 1000;
	const unsigned int screenHeight = 800;
	const unsigned int FPS = 60;
	const unsigned int tileDimension = 10;

	void Update() {
		++gametime;
	}
}

int GetGameTime() { return Globals::gametime; }
int GetGameScreenWidth() { return Globals::screenWidth; }
int GetGameScreenHeight() { return Globals::screenHeight; }
int GetGameFPS() { return Globals::FPS; }

int GetTileDimension() { return Globals::tileDimension; }

bool GameTimeSecondsPassed(const int seconds)
{
	return GetGameTime() % (seconds * GetGameFPS()) == 0;
}


