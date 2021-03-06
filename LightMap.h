#pragma once
#include <vector>
#include "raylib.h"
#include "MathFunctions.h"
#include "PrintFunctions.h"
#include "Globals.h"

namespace LightMapInfo
{
	extern bool runUpdate;
	extern unsigned int lightDecrement; //how fast the light strength decreases
	extern void Set(bool r, unsigned int l);
}

class LightSource
{
private:
	Color color; //0 alpha is no strength. higher levels equal higher strength and radius
	Vector2 pos; //map position
	bool update;

public:
	LightSource() 
	{
		color = WHITE;
		pos = Vector2{ 0.0f, 0.0f };
	}

	LightSource(Color c) : color(c) 
	{
		pos = Vector2{ 0.0f, 0.0f };
	}

	LightSource(Color c, Vector2 p) : color(c), pos(p)
	{
		LightMapInfo::runUpdate = true;
	}

	void Update() {
		if (!update)
			return;
		update = false;

		//loop through values and update colors

	}

	void SetStrength(int s)
	{
		color.a = s;
		LightMapInfo::runUpdate = true;
	}

	//todo: check if it already equals position or color before setting runUpdate to true
	void SetPosition(Vector2 p)
	{
		pos = p;
		LightMapInfo::runUpdate = true;
	}

	void SetColor(Color c)
	{
		color = c;
		LightMapInfo::runUpdate = true;
	}
	//don't return reference so they can't change it
	int GetStrength() { return color.a; }
	Vector2 GetPosition() { return pos; }
	Color GetColor() { return color; }
	float GetRadius() { return float(color.a) / float(LightMapInfo::lightDecrement); }
};

class LightMap
{
private:
	static int width;
	static int height;
	static int tileDimension;
	static std::vector<std::vector<Color>> map;	//values of lighting / shading.
	static std::vector<LightSource> lights;

public:
	static void Init(int w, int h, int t)
	{
		width = w;
		height = h;
		tileDimension = t;

		map.resize(h);
		for (int i = 0; i < map.size(); i++) {
			map.at(i).resize(w);

			for (int j = 0; j < map.at(i).size(); j++) {
				map.at(i).at(j) = BLANK; //set all rect colors to BLANK
			}
		}
	}

	static void ResetMap()
	{
		for (int y = 0; y < map.size(); y++)
			for (int x = 0; x < map.at(y).size(); x++)
				map.at(y).at(x) = BLANK;
	}

	static void Update()
	{
		//loop through the light sources and update map lighting levels
		if (!LightMapInfo::runUpdate)
			return;
		LightMapInfo::runUpdate = false;

		ResetMap();

		for (LightSource& l : lights)
		{
			//draw at position and calculate how far to loop around the position
			const Vector2 pos = l.GetPosition();

			const float radius = l.GetRadius();

			for (int x = pos.x - radius; x < (pos.x + radius); x++)
			{
				if (x < 0 || x >(width - 1)) continue;

				for (int y = pos.y - radius; y < (pos.y + radius); y++)
				{
					if (y < 0 || y >(height - 1)) continue;

					const float dist = distance(Vector2{ float(x), float(y) }, pos);

					if (dist < radius)
					{
						const int strength = l.GetStrength() - int(dist) * LightMapInfo::lightDecrement;

						Color c = l.GetColor();
						c = { (unsigned char)c.r, (unsigned char)c.g, (unsigned char)c.b, (unsigned char)strength };
						Color c2 = map.at(y).at(x);
						
						/*if (Globals::gametime % (60 * 5) == 0) {
							PrintColor(AddColors(c, c2));
						}*/

						map.at(y).at(x) = AddColors(c, c2);
					}
				}
			}
		}

	}

	static void Draw()
	{
		for (int y = 0; y < map.size(); y++)
		{
			for (int x = 0; x < map.at(y).size(); x++)
			{
				int posx = x * tileDimension;
				int posy = y * tileDimension;
				DrawRectangle(posx, posy, tileDimension, tileDimension, map.at(y).at(x));
			}
		}
	}

	static void AddLightSource(const LightSource& l)
	{
		lights.push_back(l);
		LightMapInfo::runUpdate = true;
	}

	static void DeleteLightSource(int index)
	{
		lights.erase(lights.begin() + index);
		LightMapInfo::runUpdate = true;
	}

	static int GetTileDimension() { return tileDimension; }
	static LightSource& GetLightSource(int index) { return lights.at(index); }
	static int GetLightSourceCount() { return lights.size(); }
};