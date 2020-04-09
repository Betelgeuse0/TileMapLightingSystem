#pragma once
#include <math.h>
#include "raylib.h"
#include "Globals.h"
#include "PrintFunctions.h"

inline float distance(const Vector2& v1, const Vector2& v2)
{
	return sqrt(pow(v2.x - v1.x, 2) + pow(v2.y - v1.y, 2));
}

inline Color AddColors(const Color& c1, const Color& c2)
{
	int r = c1.r + c2.r;
	if (r > 255) r = 255;

	int g = c1.g + c2.g;
	if (g > 255) g = 255;

	int b = c1.b + c2.b;
	if (b > 255) g = 255;

	int a = c1.a + c2.a;
	if (a > 255) a = 255;

	/*if (GameTimeSecondsPassed(1)) {
		Println("r: ", r);
		Println("r char: ", static_cast<unsigned char>(r));
		Println("FPS: ", GetGameFPS());
	}*/

	return Color{ (unsigned char)r, (unsigned char)g, (unsigned char)b, (unsigned char)a };
}