//fps renderer

#ifndef _FPSRENDERER_H
#define _FPSRENDERER_H
#include "spaceship.h"

class FPSCounter
{
	unsigned long elapsed;
	int fpscount;
	float fps;
	public:
	void Update(DWORD mills);
	void Draw();
	FPSCounter();
};

#endif
