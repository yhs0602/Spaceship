//name: playercontroller.cpp

#include "spaceship.h"
#include "Terrain/terrain.h"
#include "playercontroller.h"
#include "NeHeGL.h"
#include "AudioManager.h"


PlayerController::PlayerController()
{
	;
}
PlayerController::~PlayerController()
{
	;
}
		
SourceIndex src;

//Actual Init
BOOL PlayerController::Initialize()
{
	camera.Initialize();
	src=audioManager.AllocSource(SND_SHOT);
	return true;
}
BOOL PlayerController::DeInitialize()
{
	
}

void PlayerController::GetView()
{
	camera.GetView();
}

void PlayerController::Update(DWORD milliseconds)
{
	//#define HANDLE_KEY_ONCE(X,Y) \
		if(keys->keyDown[X]==TRUE)\
		if(GetAsyncKeyState())\
		{\
			keys->keyDown[X]=FALSE;\
			Y;\
		}else {}
	#define HANDLE_KEY_ONCE(X,Y)\
		if(GetKeyState(X)<0)\
		{\
			Y;\
		}
	HANDLE_KEY_ONCE('W',{camera.Walk(STEPS*milliseconds/1000);})
	HANDLE_KEY_ONCE('A',{camera.Strafe(-STEPS*milliseconds/1000);})
	HANDLE_KEY_ONCE('S',{camera.Walk(-STEPS*milliseconds/1000);})
	HANDLE_KEY_ONCE('D',{camera.Strafe(STEPS*milliseconds/1000);})
	HANDLE_KEY_ONCE(VK_SPACE,{camera.Fly(STEPS*milliseconds/1000);})
	HANDLE_KEY_ONCE(VK_SHIFT,{camera.Fly(-STEPS*milliseconds/1000);})
	HANDLE_KEY_ONCE(VK_UP,{
		float row;
		float col;
		theTerrain->getHeightMapCoord(camera.getX(),camera.getZ(),col,row);
		theTerrain->setHeightmapEntry(row,col,theTerrain->getHeightmapEntry(row,col)+STEPS*milliseconds/200);})
	HANDLE_KEY_ONCE(VK_DOWN,{
		float row;
		float col;
		theTerrain->getHeightMapCoord(camera.getX(),camera.getZ(),col,row);
		theTerrain->setHeightmapEntry(row,col,theTerrain->getHeightmapEntry(row,col)-STEPS*milliseconds/200);})
	
	#ifdef DEBUG
		HANDLE_KEY_ONCE('1',{MoveWindow(window->hWnd,100,100,window->init.width,window->init.height,FALSE);})
	#endif
	#undef HANDLE_KEY_ONCE
	vec pos=camera.getPosition();
	float height = theTerrain->getHeight( pos.x, pos.z );
	pos.y=pos.y>height+3.0f? pos.y: height+3.0f;
	//pos.y = height + 3.0f; // add height because we're standing up
	camera.setPosition(pos);

	//Now Handle Mouse.
	if(isClicked)
	{	
		isClicked=false;
		audioManager.PlaySource(src);
		camera.Pitch(0.002);
		camera.Walk(-0.02);
	}
	if(mouseRelease==false)
	{
		RECT windowrect;
		static POINT prevCursorPt={0,0}, cursorPt={0,0};
		prevCursorPt=cursorPt;
		GetCursorPos(&cursorPt);
		int dx=cursorPt.x-prevCursorPt.x;
		int dy=cursorPt.y-prevCursorPt.y;
		camera.Pitch((float(-dy)/1000));
		camera.Yaw(float(-dx)/1000);
		GetWindowRect(window->hWnd,&windowrect);
		POINT ws={windowrect.left,windowrect.top};
		POINT we={windowrect.right,windowrect.bottom};
		ClientToScreen(window->hWnd,&ws);
		ClientToScreen(window->hWnd,&we);
		RECT r={ws.x,ws.y,we.x,we.y};
		//if(!PtInRect(&r,cursorPt))
		{
			POINT m={(ws.x+we.x)/2,(ws.y+we.y)/2};
			SetCursorPos(m.x,m.y);
			cursorPt=m;
		}
	}



//int newX=0, newY=0;
//bool Mout=false;
//	if(isMMoved)
//	{
//		isMMoved=false;
//		GetCursorPos(&MousePt);
//		int dx=MousePt.x-prevMousePt.x;
//		int dy=MousePt.y-prevMousePt.y;
//		camera.Pitch((float)-dy/1000);
//		camera.Yaw((float)-dx/1000);
//	//	if(window->init.isFullScreen)
//	//	{
//	//		if((MousePt.x>scrnResX-20||MousePt.x<20)||(MousePt.y>scrnResY-20||MousePt.y<20))
//		//	{
//		//		newX=scrnResX/2;
//		//		newY=scrnResY/2;
//		//		Mout=true;
//		//	}
//		//} else 
//	
//	}
//
//		{
//			RECT crt;
//			GetWindowRect(window->hWnd,&crt);
//			//ScreenToClient(window->hWnd,&MousePt);
//			if(((MousePt.x>crt.right-40)||(MousePt.x<crt.left+40))||((MousePt.y>crt.bottom-40)||(MousePt.y<crt.top+40)))
//			{
//				newX=(crt.right+crt.left)/2;
//				newY=(crt.top+crt.bottom)/2;
//				Mout=true;
//			}
//		}
//		if(Mout)
//		{
//			Mout=false;
//			POINT pt;
//			pt.x=newX;
//			pt.y=newY;
//			//ClientToScreen(window->hWnd,&pt);
//			SetCursorPos(pt.x,pt.y);
//			//ScreenToClient(window->hWnd,&pt);
//			prevMousePt.x=pt.x;
//			prevMousePt.y=pt.y;
//			MousePt=prevMousePt;
//		}
}

