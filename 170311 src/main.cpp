//Name
#include "spaceship.h"
#include "playercontroller.h"
#include "audiomanager.h"
#include "fps2.h"
#include "GLutil.h"
#include "terrain/terrain.h"


POINT MousePt;
POINT prevMousePt;
bool        isClicked;
bool        isRClicked; 
bool 		isMMoved;
Keys 		*keys;
GL_Window 	*window;
bool 		mouseRelease;

PlayerController playerController;
AudioManager audioManager;
FPSCounter fpsCounter;
Terrain *theTerrain;

BOOL Initialize (GL_Window* _window, Keys* _keys)
{
	window=_window;
	keys=_keys;
	isClicked=false;
	isRClicked=false;
	isMMoved=false;
	srand(time(NULL));
	//Init OpenAL fREAmeWork
		//ALFWInit();
	//init OpenAL
	//if(ALFWInitOpenAL()==AL_FALSE);
	//	return FALSE;
	if(InitGL()==FALSE)
	{
		return false;
	}
	if(!audioManager.Initialize())
	{
		Warning("audiomanager");
	}
	if(!playerController.Initialize())
	{
		Error("playerController");
		return false;
	}
	theTerrain=new Terrain( "Terrain/coastMountain64.raw", 64, 64, 10, 0.5f);
	if(theTerrain==NULL)
	{
		Error("no terrain data!!!");
		return false;
	}
	return true;	
}

void Deinitialize (void)
{
//	ALFWShutdownOpenAL();
//	ALFWShutdown();
	DeInitGL();
	audioManager.DeInitialize();
	delete theTerrain;
}

void Update (DWORD milliseconds)				// Perform Motion Updates
{
	#define _DEBUG
	#ifdef _DEBUG
		if(keys->keyDown[VK_ESCAPE]==true)
		{
			keys->keyDown[VK_ESCAPE]=false;
			mouseRelease=!mouseRelease;
			ClipCursor(NULL);
		}
	#endif
	playerController.Update(milliseconds);
	fpsCounter.Update(milliseconds);
}

