#include "LightMap.h"

namespace LightMapInfo 
{
	bool runUpdate = false;
	unsigned int lightDecrement = 4; //how fast the light strength decreases

	void Set(bool r, unsigned int l) {
		runUpdate = r;
		lightDecrement = l;
	}
}

int LightMap::width;
int LightMap::height;
int LightMap::tileDimension;
std::vector<std::vector<Color>> LightMap::map;
std::vector<LightSource> LightMap::lights;