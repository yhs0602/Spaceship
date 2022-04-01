//fpscounter.cpp

#include "spaceship.h"
#include "fps2.h"
#include "glutil.h"



void FPSCounter::Update(DWORD mills)
{
	elapsed+=mills;
	fpscount++;
	if(elapsed>=1000)
	{
		fps=(float)fpscount/elapsed*1000;
		fpscount=0;
		elapsed=0;
	}
}
void FPSCounter::Draw()
{
	glPushMatrix();
		// Blue Text
	//glColor3f(0,0,0.8f);
	// Position The WGL Text On The Screen
	glColor3f(1,1,1);
	glRasterPos2f(0.40f, 0.35f);
	glPrint("%3.2f",fps);
	glPopMatrix();
}
FPSCounter::FPSCounter()
{
	fpscount=0;
	fps=40.0f;
	elapsed=0;
}
