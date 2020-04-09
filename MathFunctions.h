#pragma once
#include <math.h>
#include "raylib.h"

inline float distance(const Vector2& v1, const Vector2& v2)
{
	return sqrt(pow(v2.x - v1.x, 2) + pow(v2.y - v1.y, 2));
}