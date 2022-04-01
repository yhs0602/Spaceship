#if 0
//Desc: Terrain.cpp
#include "spaceship.h"


terunit World::GetHeight(terunit x, terunit z)
{
	Chunk &c=FindChunk(terunit x, terunit z);
	return c.GetHeight(x,z);
}

bool World::LoadTerrain(string fname)
{
	return 0;
}

bool World::SetBlock(Block &b, terunit x,terunit y, terunit z)
{
	return true;
}

Chunk &FindChunk(terunit x, terunit z)
{
	return chunks[0];
}

#endif
