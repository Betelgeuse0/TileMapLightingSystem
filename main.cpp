#include "raylib.h"
#include "LightMap.h"

void main()
{
	const int screenWidth = 800;
	const int screenHeight = 450;

	InitWindow(screenWidth, screenHeight, "Light Map Tile System");
	SetTargetFPS(60);

	LightMapInfo::lightDecrement = 5;

	const int td = 10;
	LightMap::Init(screenWidth / td, screenHeight / td, td);

	LightSource l(Color{ 0, 0, 255, 255 }, Vector2{ 40, 20 });
	LightMap::AddLightSource(l);

				
	while (!WindowShouldClose())    
	{
		LightMap::Update();

		BeginDrawing();
			ClearBackground(BLACK);
			LightMap::Draw();
		EndDrawing();

	}
	CloseWindow();
}