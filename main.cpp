#include "raylib.h"
#include "LightMap.h"
#include "MouseLight.h"
#include "Globals.h"
#include "Test.h"

void main()
{
	//InitWindow(GetScreenWidth(), GetScreenHeight(), "Light Map Tile System");
	int screenWidth = GetGameScreenWidth();
	int screenHeight = GetGameScreenHeight();

	InitWindow(screenWidth, screenHeight, "Light Map Tile System");
	SetTargetFPS(GetGameFPS());

	LightMapInfo::lightDecrement = 10;

	const int td = GetTileDimension();
	LightMap::Init(screenWidth / td, screenHeight / td, td);

	LightSource l(Color{ 0, 0, 255, 255 }, Vector2{ 50, 40 });
	LightMap::AddLightSource(l);
	
	LightSource l2(Color{ 255, 0, 0, 255 });
	MouseLight::Init(l2);
				
	while (!WindowShouldClose())    
	{
		LightMap::Update();
		MouseLight::Update();
		Globals::Update();		//keep this last
			
		BeginDrawing();
			ClearBackground(BLACK);
			LightMap::Draw();
		EndDrawing();
	}
	CloseWindow();
}