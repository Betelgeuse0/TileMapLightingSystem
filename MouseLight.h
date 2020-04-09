#pragma once
#include "raylib.h"
#include "LightMap.h"

namespace MouseLight
{
	extern int index; //the index where the light source is stored in map
	extern bool init;
	extern void Init(const LightSource& l);
	extern void Update();
}