#ifndef _TOT_H
#define _TOT_H
#define DEBUG 1

#define WIN32_LEAN_AND_MEAN
#define _WINSVC_H
#define _WINNETWK_H
#define _WINVER_H
#include <windows.h>		// Header File For Windows

#include <gl\gl.h>			// Header File For The OpenGL32 Library
#include <gl\glu.h>			// Header File For The GLu32 Library
//#include <gl\glaux.h>		// Header File For The Glaux Library
#include <al\al.h>
#include <al\alc.h>

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <exception>
#include "geom.h"

static inline void Warning(const char * str)
{
	MessageBox(0,str,"warning",0);
}
static inline void Error(const char * str)
{
	MessageBox(0,str,"Error",0);
}


class World;
class FPSCounter;
class Camera;
class Chunk;
class Block;
class PlayerController;
class PhysicsManager;
class AudioManager;
//struct Keys;
//struct GL_Window;

#define GLvoid void
#define STEPS 15.0f
//#include "log.h"
//#include "camera.h"
//#include "PhyEnt.h"
//#include "AudioManager.h"
////#include "PhysicsManager.h"
//#include "FPS2.h"
//#include "GLUtil.h"
#include "NeHeGL.h"
//#include "terrain.h"
//#include "Terrain/terrain.h"
//#include "main.h"
//#include "PlayerController.h"
//#include "bound.h"
extern POINT MousePt;
extern POINT prevMousePt;
extern bool        isClicked;
extern bool        isRClicked; 
extern bool 		isMMoved;
extern bool 		mouseRelease;
extern Keys 		*keys;
extern GL_Window 	*window;
extern class PlayerController playerController;
extern class AudioManager audioManager;
extern class FPSCounter fpsCounter;
extern class Terrain *theTerrain;
//extern PhysicsManager physicsManager;
#endif
