#include "MouseLight.h"

namespace MouseLight
{
	//LightSource light;
	int index = 0;
	bool init = false;

	void Init(const LightSource& l)
	{
		init = true;
		LightMap::AddLightSource(l);
		index = LightMap::GetLightSourceCount() - 1;
	}

	void Update()
	{
		if (!init) return;

		Vector2 pos{ GetMouseX() / LightMap::GetTileDimension(), GetMouseY() / LightMap::GetTileDimension() };
		LightMap::GetLightSource(index).SetPosition(pos);
	}
}


